package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "freeglut/freeglut/include/**/*.h",
        "freeglut/freeglut/src/*.h",
        "freeglut/freeglut/src/util/*.h",
        "freeglut/freeglut/src/x11/*.h",
        "freeglut/freeglut/src/egl/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "freeglut/freeglut/src/*.c",
        "freeglut/freeglut/src/x11/*.c",
        #"freeglut/freeglut/src/egl/*.c",
    ],
    exclude = [
        "freeglut/freeglut/src/fg_font.c",
        "freeglut/freeglut/src/fg_menu.c",
        "freeglut/freeglut/src/x11/fg_window_x11_glx.c",
        "freeglut/freeglut/src/x11/fg_state_x11_glx.c",
    ],
)

cc_library(
    name = "FreeGLUT",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        "-DFREEGLUT_GLES",
    ],
    includes = [
        ".",
        "freeglut/freeglut",
        "freeglut/freeglut/include",
        "freeglut/freeglut/include/GL",
        "freeglut/freeglut/src",
        "freeglut/freeglut/src/util",
        "include",
        "src",
    ],
    #strip_include_prefix = "freeglut/freeglut",
    deps = [
        "@mesa",
    ],
)
