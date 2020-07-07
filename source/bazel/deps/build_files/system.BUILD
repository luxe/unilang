package(
    default_visibility = ["//visibility:public"],
)

# Ideally we don't want to create these, but sometimes things are too hard to build from source

#shared objects
cc_import(
    name = "glib",
    shared_library = "usr/lib/x86_64-linux-gnu/libglib-2.0.so",
)

cc_import(
    name = "libcpp",
    shared_library = "usr/lib/x86_64-linux-gnu/libstdc++.so.6",
)

cc_import(
    name = "libc",
    shared_library = "usr/lib/x86_64-linux-gnu/libc.so",
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
    name = "SDL_mixer",
    shared_library = "usr/lib/x86_64-linux-gnu/libSDL_mixer.so",
)

cc_import(
    name = "openal",
    shared_library = "usr/lib/x86_64-linux-gnu/libopenal.so",
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

cc_import(
    name = "SFML_audio",
    shared_library = "usr/lib/x86_64-linux-gnu/libsfml-audio.so",
)

cc_import(
    name = "SFML_graphics",
    shared_library = "usr/lib/x86_64-linux-gnu/libsfml-graphics.so",
)

cc_import(
    name = "SFML_network",
    shared_library = "usr/lib/x86_64-linux-gnu/libsfml-network.so",
)

cc_import(
    name = "SFML_system",
    shared_library = "usr/lib/x86_64-linux-gnu/libsfml-system.so",
)

cc_import(
    name = "SFML_window",
    shared_library = "usr/lib/x86_64-linux-gnu/libsfml-window.so",
)

cc_import(
    name = "gmp",
    shared_library = "usr/lib/x86_64-linux-gnu/libgmp.so",
)

cc_import(
    name = "gmpxx",
    shared_library = "usr/lib/x86_64-linux-gnu/libgmpxx.so",
)

cc_import(
    name = "libgudev",
    shared_library = "usr/lib/x86_64-linux-gnu/libgudev-1.0.so.0",
)

cc_import(
    name = "sndio",
    shared_library = "usr/lib/x86_64-linux-gnu/libsndio.so",
)

cc_import(
    name = "uuid",
    shared_library = "usr/lib/x86_64-linux-gnu/libuuid.so",
)

#headers
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

cc_library(
    name = "SDL2_hdrs",
    hdrs = glob(["usr/include/SDL2/**/*.h"]),
    includes = ["usr/include/SDL2"],
)

cc_library(
    name = "EGL_hdrs",
    hdrs = glob(["usr/include/EGL/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "SFML_hdrs",
    hdrs = glob([
        "usr/include/SFML/**/*.hpp",
        "usr/include/SFML/**/*.inl",
    ]),
    includes = ["usr/include"],
)
