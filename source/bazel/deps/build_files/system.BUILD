package(
    default_visibility = ["//visibility:public"],
)

#shared objects
cc_import(
    name = "glib",
    shared_library = "usr/lib/x86_64-linux-gnu/libglib-2.0.so",
)

cc_import(
    name = "GL",
    shared_library = "usr/lib/libGL.so",
)
cc_import(
    name = "GLEW",
    shared_library = "usr/lib/x86_64-linux-gnu/libGLEW.so",
)
cc_import(
    name = "GLU",
    shared_library = "usr/lib/x86_64-linux-gnu/libGLU.so",
)
cc_import(
    name = "glut",
    shared_library = "usr/lib/x86_64-linux-gnu/libglut.so",
)
cc_import(
    name = "GLX",
    shared_library = "usr/lib/x86_64-linux-gnu/libGLX.so",
)

cc_import(
    name = "GLX_mesa",
    shared_library = "usr/lib/x86_64-linux-gnu/libGLX_mesa.so.0",
)
cc_import(
    name = "EGL_mesa",
    shared_library = "usr/lib/x86_64-linux-gnu/libEGL_mesa.so.0",
)

cc_import(
    name = "SDL2",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL2.so",
)
cc_import(
    name = "SDL2_image",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL2_image.so",
)
cc_import(
    name = "SDL2_mixer",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL2_mixer.so",
)
cc_import(
    name = "SDL2_net",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL2_net.so",
)

cc_import(
    name = "glfw",
    shared_library = "usr/lib/x86_64-linux-gnu/libglfw.so",
)

cc_library(
    name = "GL_hdrs",
    hdrs = glob(["usr/include/GL/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "X11_hdrs",
    hdrs = glob(["usr/include/X11/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "KHR_hdrs",
    hdrs = glob(["usr/include/KHR/**/*.h"]),
    includes = ["usr/include"],
)

