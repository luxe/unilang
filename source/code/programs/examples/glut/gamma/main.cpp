/* gamma.c */

/* Draw test patterns to help determine correct gamma value for a display.
   When the intensities in the top row nearly match the intensities in
   the bottom row you've found the right gamma value.

   For more info about gamma correction see:
   http://www.inforamp.net/~poynton/notes/colour_and_gamma/GammaFAQ.html

   This program is in the public domain

   Brian Paul  19 Oct 1995 */

/* Conversion to GLUT by Mark J. Kilgard */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <GL/glut.h>

static void 
Reshape(int width, int height)
{
  glViewport(0, 0, (GLint) width, (GLint) height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

/* ARGSUSED1 */
static void 
key_esc(unsigned char key, int x, int y)
{
  if(key == 27) exit(0);  /* Exit on Escape */
}

static GLubyte p25[] =
{
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
  0xaa, 0xaa, 0xaa, 0xaa, 0x00, 0x00, 0x00, 0x00,
};

static GLubyte p50[] =
{
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
  0xaa, 0xaa, 0xaa, 0xaa, 0x55, 0x55, 0x55, 0x55,
};

static GLubyte p75[] =
{
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
  0xaa, 0xaa, 0xaa, 0xaa, 0xff, 0xff, 0xff, 0xff,
};

static void 
display(void)
{

  glClear(GL_COLOR_BUFFER_BIT);

/** DITHERED ROW **/

  /* solid black */

  /* 25% white */
  glEnable(GL_POLYGON_STIPPLE);
  glColor3f(1.0, 1.0, 1.0);
  glPolygonStipple(p25);
  glRectf(-0.6, 1.0, -0.2, 0.01);

  /* 50% white */
  glPolygonStipple(p50);
  glRectf(-0.2, 1.0, 0.2, 0.01);

  /* 75% white */
  glPolygonStipple(p75);
  glRectf(0.2, 1.0, 0.6, 0.01);

  /* 100% white */
  glDisable(GL_POLYGON_STIPPLE);
  glRectf(0.6, 1.0, 1.0, 0.01);

/*** GRAY ROW ***/

  /* solid black */

  /* 25% white */
  glColor3f(0.25, 0.25, 0.25);
  glRectf(-0.6, -0.01, -0.2, -1.0);

  /* 50% white */
  glColor3f(0.5, 0.5, 0.5);
  glRectf(-0.2, -0.01, 0.2, -1.0);

  /* 75% white */
  glColor3f(0.75, 0.75, 0.75);
  glRectf(0.2, -0.01, 0.6, -1.0);

  /* 100% white */
  glColor3f(1.0, 1.0, 1.0);
  glRectf(0.6, -0.01, 1.0, -1.0);

  glFlush();
}

int 
main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

  glutInitWindowPosition(50, 50);
  glutInitWindowSize(400, 200);

  glutCreateWindow("gamma test patterns");
  glutReshapeFunc(Reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(key_esc);

  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}