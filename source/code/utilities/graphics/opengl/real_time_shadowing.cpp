
/* Copyright (c) Mark J. Kilgard, 1997.  */

/* This program is freely distributable without licensing fees  and is
   provided without guarantee or warrantee expressed or  implied. This
   program is -not- in the public domain. */

/* This example shows how to use the GLU polygon tessellator to determine the
   2D boundary of OpenGL rendered objects.  The program uses OpenGL's feedback
   mechanim to capture transformed polygons and then feeds them to the GLU 1.2
   tesselator in GLU_TESS_WINDING_NONZERO and GLU_TESS_BOUNDARY_ONLY mode. 
   Then, a primitive shadow volume is contructed. */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <glu.h>

#include "code/utilities/graphics/opengl/real_time_shadowing.hpp"

const float uniquePassThroughValue = 34567.0;

#define SmallerOf(a,b) ((a) < (b) ? (a) : (b))

/* Coordinates. */
enum {
  X, Y, Z
};

struct VertexHolder {
  struct VertexHolder *next;
  GLfloat v[2];
};

typedef struct _ShadowVolumeMemoryPool {
  /* Reference count because ShadowVolumeMemoryPool's can be shared between
     multiple ShadowVolumeState's. */
  int refcnt;

  GLUtesselator *tess;
  GLfloat viewScale;

  /* Memory used for GLU tessellator combine callbacks. */
  GLfloat *combineList;
  int combineListSize;
  int combineNext;
  struct VertexHolder *excessList;
} ShadowVolumeMemoryPool;

struct ShadowVolumeStateType {
  ShadowVolumeMemoryPool *pool;

  int regenerateNeeded;
  GLfloat objectPos[3];
  GLfloat maxRadius;
  GLfloat eyePos[3];
  GLfloat lightPos[4];
  GLfloat shadowDistance;
  int feedbackBufferSizeGuess;
  void (*renderFunc)(void *data);
  void *renderData;

  GLfloat extentScale;

  /* Display lists. */
  GLuint base;
  GLuint shadowVolume;
  GLuint shadowVolumeTop;

  /* Scratch variables used during GLU tessellator callbacks. */
  int saveFirst;
  GLfloat *firstVertex;
};

int renderBoundary; /* XXX */

static void
begin(GLenum type, void *shadowVolumeState)
{
  ShadowVolumeStateType *svs = (ShadowVolumeStateType *) shadowVolumeState;

  assert(type == GL_LINE_LOOP);
  if (renderBoundary) {
    glBegin(type);
  } else {
    svs->saveFirst = 1;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 1, 0);
    glVertex3f(0.0, 0.0, 0.0);
  }
}

static void
vertex(void *data, void *shadowVolumeState)
{
  ShadowVolumeStateType *svs = (ShadowVolumeStateType *) shadowVolumeState;
  GLfloat *v = (float*)data;

  if (renderBoundary) {
    glVertex2fv(v);
  } else {
    if (svs->saveFirst) {
      svs->firstVertex = v;
      svs->saveFirst = 0;
    }
    glColor3f(0, 0, 1);
    glVertex3f(svs->extentScale * v[X], svs->extentScale * v[Y],
      svs->shadowDistance);
  }
}

static void
end(void *shadowVolumeState)
{
  ShadowVolumeStateType *svs = (ShadowVolumeStateType *) shadowVolumeState;

  if (!renderBoundary) {
    glColor3f(0, 0, 1);
    glVertex3f(svs->extentScale * svs->firstVertex[X], svs->extentScale * svs->firstVertex[Y],
      svs->shadowDistance);
  }
  glEnd();
}

static void
freeExcessList(ShadowVolumeMemoryPool * pool)
{
  struct VertexHolder *holder, *next;

  holder = pool->excessList;
  while (holder) {
    next = holder->next;
    free(holder);
    holder = next;
  }
  pool->excessList = NULL;
}

/* ARGSUSED1 */
static void
combine(GLdouble coords[3], void *d[4], GLfloat w[4], void **dataOut, void *shadowVolumeState)
{
  ShadowVolumeStateType *svs = (ShadowVolumeStateType *) shadowVolumeState;
  ShadowVolumeMemoryPool *pool = svs->pool;
  struct VertexHolder *holder;
  GLfloat *new_var;

  if (pool->combineNext >= pool->combineListSize) {
    holder = (struct VertexHolder *) malloc(sizeof(struct VertexHolder));
    holder->next = pool->excessList;
    pool->excessList = holder;
    new_var = holder->v;
  } else {
    new_var = &pool->combineList[pool->combineNext * 2];
  }

  new_var[X] = coords[X];
  new_var[Y] = coords[Y];
  *dataOut = new_var;

  pool->combineNext++;
}

static void
error(GLenum errno)
{
  printf("ERROR: %s\n", gluErrorString(errno));
}

static void
processFeedback(GLint size, GLfloat * buffer, ShadowVolumeStateType * svs)
{
  ShadowVolumeMemoryPool *pool = svs->pool;
  GLfloat *loc, *end, *eyeLoc;
  GLdouble v[3];
  int token, nvertices, i;
  GLfloat passThroughToken;
  int watchingForEyePos;

  if (pool->combineNext > pool->combineListSize) {
    freeExcessList(pool);
    pool->combineListSize = pool->combineNext;
    pool->combineList = (float*)realloc(pool->combineList, sizeof(GLfloat) * 2 * pool->combineListSize);
  }
  pool->combineNext = 0;

  watchingForEyePos = 0;
  eyeLoc = NULL;

#ifdef GLU_VERSION_1_2
  glColor3f(1, 1, 1);
  gluTessBeginPolygon(pool->tess, svs);
  loc = buffer;
  end = buffer + size;
  while (loc < end) {
    token = *loc;
    loc++;
    switch (token) {
    case GL_POLYGON_TOKEN:
      nvertices = *loc;
      loc++;
      assert(nvertices >= 3);
      gluTessBeginContour(pool->tess);
      for (i = 0; i < nvertices; i++) {
        v[X] = loc[X];
        v[Y] = loc[Y];
        v[Z] = 0.0;
        gluTessVertex(pool->tess, v, loc);
        loc += 2;
      }
      gluTessEndContour(pool->tess);
      break;
    case GL_PASS_THROUGH_TOKEN:
      passThroughToken = *loc;
      if (passThroughToken == uniquePassThroughValue) {
        watchingForEyePos = !watchingForEyePos;
      } else {
        /* Ignore everything else. */
        fprintf(stderr, "ERROR: Unexpected feedback token 0x%x (%d).\n", token, token);
      }
      loc++;
      break;
    case GL_POINT_TOKEN:
      if (watchingForEyePos) {
        fprintf(stderr, "WARNING: Eye point possibly within the shadow volume.\n");
        fprintf(stderr, "         Program should be improved to handle this.\n");
        /* XXX Write code to handle this case.  You would need to determine
           if the point was instead any of the returned boundary polyons.
           Once you found that you were really in the clipping volume, then I
           haven't quite thought about what you do. */
        eyeLoc = loc;
        watchingForEyePos = 0;
      } else {
        /* Ignore everything else. */
        fprintf(stderr, "ERROR: Unexpected feedback token 0x%x (%d).\n",
          token, token);
      }
      loc += 2;
      break;
    default:
      /* Ignore everything else. */
      fprintf(stderr, "ERROR: Unexpected feedback token 0x%x (%d).\n",
        token, token);
    }
  }
  gluTessEndPolygon(pool->tess);

  if (eyeLoc) {
    glColor3f(0, 1, 0);
    glPointSize(7.0);
    glBegin(GL_POINTS);
    glVertex2fv(eyeLoc);
    glEnd();
  }
#endif
}

/* Three element vector dot product. */
static GLfloat
vdot(const GLfloat * v1, const GLfloat * v2)
{
  return v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z];
}

/* Three element vector cross product. */
static void
vcross(const GLfloat * v1, const GLfloat * v2, GLfloat * cross)
{
  assert(v1 != cross && v2 != cross);
  cross[X] = (v1[Y] * v2[Z]) - (v1[Z] * v2[Y]);
  cross[Y] = (v1[Z] * v2[X]) - (v1[X] * v2[Z]);
  cross[Z] = (v1[X] * v2[Y]) - (v1[Y] * v2[X]);
}

void
rtsFreeShadowVolumeState(ShadowVolumeStateType * svs)
{
  if (svs->pool) {
    svs->pool->refcnt--;
    if (svs->pool->refcnt == 0) {
      if (svs->pool->excessList) {
        freeExcessList(svs->pool);
      }
      if (svs->pool->combineList) {
        free(svs->pool->combineList);
      }
      if (svs->pool->tess) {
        gluDeleteTess(svs->pool->tess);
      }
      free(svs->pool);
    }
  }
  free(svs);
}

ShadowVolumeStateType *
rtsCreateShadowVolumeStateType(ShadowVolumeStateType * shareSVS)
{
  ShadowVolumeStateType *svs;
  ShadowVolumeMemoryPool *pool;
  GLUtesselator *tess;

  svs = (ShadowVolumeStateType *) malloc(sizeof(ShadowVolumeStateType));
  if (svs == NULL) {
    return NULL;
  }
  svs->pool = NULL;

  if (shareSVS == NULL) {
    pool = (ShadowVolumeMemoryPool *) malloc(sizeof(ShadowVolumeMemoryPool));
    if (pool == NULL) {
      rtsFreeShadowVolumeState(svs);
      return NULL;
    }
    pool->refcnt = 1;
    pool->excessList = NULL;
    pool->combineList = NULL;
    pool->combineListSize = 0;
    pool->combineNext = 0;
    pool->tess = NULL;
    svs->pool = pool;

#ifdef GLU_VERSION_1_2
    tess = gluNewTess();
    if (tess == NULL) {
      rtsFreeShadowVolumeState(svs);
      return NULL;
    }
    gluTessProperty(tess, GLU_TESS_BOUNDARY_ONLY, GL_TRUE);
    gluTessProperty(tess, GLU_TESS_WINDING_RULE, GLU_TESS_WINDING_NONZERO);
    gluTessCallback(tess, GLU_TESS_BEGIN_DATA, (_GLUfuncptr)begin);
    gluTessCallback(tess, GLU_TESS_VERTEX_DATA, (_GLUfuncptr)vertex);
    gluTessCallback(tess, GLU_TESS_COMBINE_DATA, (_GLUfuncptr)combine);
    gluTessCallback(tess, GLU_TESS_END_DATA, (_GLUfuncptr)end);
    gluTessCallback(tess, GLU_TESS_ERROR, (_GLUfuncptr)error);
#else
    fprintf(stderr, "svsCreateShadowVolumeState: Sorry, this API requires GLU 1.2's updated tessellator.\n");
    abort();
    /* NOTREACHED */
#endif
    pool->tess = tess;
  } else {
    pool = shareSVS->pool;
    pool->refcnt++;
  }

  svs->pool = pool;
  svs->shadowDistance = 1000.0;

  return svs;
}

void
rtsSpecifyFeedbackBufferSizeGuess(ShadowVolumeStateType * svs, float guess)
{
  svs->feedbackBufferSizeGuess = guess;
}

void
rtsSpecifyObjectPos(ShadowVolumeStateType * svs, GLfloat pos[3])
{
  svs->regenerateNeeded = 1;
  svs->objectPos[X] = pos[X];
  svs->objectPos[Y] = pos[Y];
  svs->objectPos[Z] = pos[Z];
}

void
rtsSpecifyObjectMaxRadius(ShadowVolumeStateType * svs, GLfloat maxRadius)
{
  svs->regenerateNeeded = 1;
  svs->maxRadius = maxRadius;
}

void
rtsSpecifyLightPos(ShadowVolumeStateType * svs, GLfloat pos[3])
{
  svs->regenerateNeeded = 1;
  svs->lightPos[X] = pos[X];
  svs->lightPos[Y] = pos[Y];
  svs->lightPos[Z] = pos[Z];
}

void
rtsSpecifyShadowDistance(ShadowVolumeStateType * svs, GLfloat shadowDistance)
{
  svs->regenerateNeeded = 1;
  svs->shadowDistance = shadowDistance;
}

void
rtsSpecifyEyePos(ShadowVolumeStateType * svs, GLfloat pos[3])
{
  svs->regenerateNeeded = 1;
  svs->eyePos[X] = pos[X];
  svs->eyePos[Y] = pos[Y];
  svs->eyePos[Z] = pos[Z];
}

void
rtsSpecifyObjectCallback(ShadowVolumeStateType * svs, void (*func)(void *data), void *data)
{
  svs->regenerateNeeded = 1;
  svs->renderFunc = func;
  svs->renderData = data;
}

int
rtsSpecifyDisplayLists(ShadowVolumeStateType * svs, GLuint lists[3])
{
  if (lists) {
    svs->base = lists[0];
    svs->shadowVolume = lists[1];
    svs->shadowVolumeTop = lists[2];
  } else {
    svs->base = glGenLists(3);
    svs->shadowVolume = svs->base + 1;
    svs->shadowVolumeTop = svs->base + 2;
  }
  return 1;
}

static void
generateShadowVolume(ShadowVolumeStateType * svs)
{
  static GLfloat unit[3] =
  {0.0, 0.0, 1.0};
  static GLfloat *feedbackBuffer = NULL;
  static int bufferSize = 0;
  GLfloat axis[3], lightDelta[3], eyeDelta[3];
  GLfloat nnear, ffar;  /* Avoid Intel C keywords.  Grumble. */
  GLfloat lightDistance, eyeDistance, angle, fieldOfViewRatio, fieldOfViewAngle,
    topScale, viewScale;
  GLint returned;

  if (svs->pool->viewScale == 0.0) {
    GLfloat maxViewSize[2];

    glGetFloatv(GL_MAX_VIEWPORT_DIMS, maxViewSize);
    printf("max viewport = %gx%g\n", maxViewSize[0], maxViewSize[1]);
    svs->pool->viewScale = SmallerOf(maxViewSize[0], maxViewSize[1]) / 2.0;
  }
  viewScale = svs->pool->viewScale;

  if (bufferSize > svs->feedbackBufferSizeGuess) {
    svs->feedbackBufferSizeGuess = bufferSize;
  }
  /* Calculate the light's distance from the object being shadowed. */
  lightDelta[X] = svs->objectPos[X] - svs->lightPos[X];
  lightDelta[Y] = svs->objectPos[Y] - svs->lightPos[Y];
  lightDelta[Z] = svs->objectPos[Z] - svs->lightPos[Z];
  lightDistance = sqrt(lightDelta[X] * lightDelta[X] +
    lightDelta[Y] * lightDelta[Y] + lightDelta[Z] * lightDelta[Z]);

  /* Determine the appropriate field of view.  We want to use as narrow a
     field of view as possible to not waste resolution, but not narrower than
     the object.  Add 50% extra slop. */
  fieldOfViewRatio = svs->maxRadius / lightDistance;
  if (fieldOfViewRatio > 0.99) {
    fprintf(stderr, "WARNING: Clamping FOV to 164 degrees for determining shadow boundary.\n");
    fprintf(stderr, "         Light distance = %g, object maxmium radius = %g\n",
      lightDistance, svs->maxRadius);

    /* 2*asin(0.99) ~= 164 degrees. */
    fieldOfViewRatio = 0.99;
  }
  /* Pre-compute scaling factors for the near and far extent of the shadow
     volume. */
  svs->extentScale = svs->shadowDistance * fieldOfViewRatio / viewScale;

  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();

  nnear = 0.5 * (lightDistance - svs->maxRadius);
  if (nnear < 0.0001) {
    fprintf(stderr, "WARNING: Clamping near clip plane to 0.0001 because light source too near.\n");
    fprintf(stderr, "         Light distance = %g, object maxmium radius = %g\n",
      lightDistance, svs->maxRadius);
    nnear = 0.0001;
  }
  ffar = 2.0 * (lightDistance + svs->maxRadius);

  eyeDelta[X] = svs->eyePos[X] - svs->lightPos[X];
  eyeDelta[Y] = svs->eyePos[Y] - svs->lightPos[Y];
  eyeDelta[Z] = svs->eyePos[Z] - svs->lightPos[Z];
  eyeDistance = 1.05 * sqrt(eyeDelta[X] * eyeDelta[X] + eyeDelta[Y] * eyeDelta[Y] + eyeDelta[Z] * eyeDelta[Z]);
  if (eyeDistance > ffar) {
    ffar = eyeDistance;
  }

  fieldOfViewAngle = 2.0 * asin(fieldOfViewRatio) * 180 / M_PI;
  gluPerspective(fieldOfViewAngle, 1.0, nnear, ffar);

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  gluLookAt(svs->lightPos[X], svs->lightPos[Y], svs->lightPos[Z],
    svs->objectPos[X], svs->objectPos[Y], svs->objectPos[Z],
    0.0, 1.0, 0.0);     /* up is in positive Y direction */

  glPushAttrib(GL_VIEWPORT_BIT);
  glViewport(-viewScale, -viewScale, 2 * viewScale, 2 * viewScale);

doFeedback:

  /* XXX Careful, some systems still don't understand realloc of NULL. */
  if (bufferSize < svs->feedbackBufferSizeGuess) {
    bufferSize = svs->feedbackBufferSizeGuess;
    /* XXX Add 32 words of slop (an extra cache line) to end for buggy
       hardware that uses DMA to return feedback results but that sometimes
       overrun the buffer.  Yuck. */
    feedbackBuffer = (float*)realloc(feedbackBuffer, bufferSize * sizeof(GLfloat) + 32 * 4);
  }
  glFeedbackBuffer(bufferSize, GL_2D, feedbackBuffer);

  (void) glRenderMode(GL_FEEDBACK);

  (svs->renderFunc) (svs->renderData);

  /* Render the eye position.  The eye position is "bracketed" by
     unique pass through tokens.  These bracketing pass through tokens
     let us determine if the eye position was clipped or not.  This
     helps us determine whether the eye position is possibly within the
     shadow volume or not.  If the point is clipped, the eye position
     is not in the shadow volume.  If the point is not clipped, a more
     complicated test is necessary to determine if the eye position is
     really in the shadow volume or not.  See processFeedback. */
  glPassThrough(uniquePassThroughValue);
  glBegin(GL_POINTS);
  glVertex3fv(svs->eyePos);
  glEnd();
  glPassThrough(uniquePassThroughValue);

  returned = glRenderMode(GL_RENDER);
#if 0
  if (returned == -1) {
#else
  /* XXX RealityEngine workaround.  Grumble. */
  if (returned == -1 || returned == svs->feedbackBufferSizeGuess) {
#endif
    svs->feedbackBufferSizeGuess = svs->feedbackBufferSizeGuess + (svs->feedbackBufferSizeGuess >> 1);
    goto doFeedback;    /* Try again with larger feedback buffer. */
  }
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glPopAttrib();        /* Restore viewport. */

#if 0
  if (renderBoundary) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-viewScale, viewScale, -viewScale, viewScale);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    processFeedback(returned, feedbackBuffer, svs);
  } else {
#endif
    glNewList(svs->base, GL_COMPILE);
    vcross(unit, lightDelta, axis);
    angle = acos(vdot(unit, lightDelta) / lightDistance) * 180.0 / M_PI;
    glRotatef(angle, axis[X], axis[Y], axis[Z]);
    processFeedback(returned, feedbackBuffer, svs);
    glEndList();

    glNewList(svs->shadowVolume, GL_COMPILE);
    glPushMatrix();
    glTranslatef(svs->lightPos[X], svs->lightPos[Y], svs->lightPos[Z]);
    glCallList(svs->base);
    glPopMatrix();
    glEndList();

    glNewList(svs->shadowVolumeTop, GL_COMPILE);
    glPushMatrix();
    glTranslatef(svs->lightPos[X], svs->lightPos[Y], svs->lightPos[Z]);
    topScale = (lightDistance + svs->maxRadius) / svs->shadowDistance;
    glScalef(topScale, topScale, topScale);
    glCallList(svs->base);
    glPopMatrix();
    glEndList();
#if 0
  }
  return returned;
#endif
}

void
rtsRenderShadowVolumes(int n, ShadowVolumeStateType ** svs)
{
  int i;

  for (i=0; i<n; i++) {
    if (svs[i]->regenerateNeeded) {
      generateShadowVolume(svs[i]);
    }
  }
}
