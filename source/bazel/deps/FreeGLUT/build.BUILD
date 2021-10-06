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
        "freeglut/freeglut/src/egl/*.c",
        "freeglut/freeglut/src/util/*.c",
    ],
    exclude = [
        "freeglut/freeglut/src/fg_font.c",
        "freeglut/freeglut/src/fg_menu.c",
        "freeglut/freeglut/src/x11/fg_window_x11_glx.c",
        "freeglut/freeglut/src/x11/fg_state_x11_glx.c",
        #"freeglut/freeglut/src/egl/fg_display_egl.c",
        #"freeglut/freeglut/src/fg_callbacks.c",

        #remove these
        # "freeglut/freeglut/src/fg_misc.c",
        # "freeglut/freeglut/src/fg_state_egl.c",
        # "freeglut/freeglut/src/fg_callbacks.c",
        # "freeglut/freeglut/src/fg_input_devices.c",
        # "freeglut/freeglut/src/fg_main.c",
        # "freeglut/freeglut/src/fg_structure.c",
        # "freeglut/freeglut/src/egl/fg_state_egl.c",

        #"freeglut/freeglut/src/egl/fg_display_egl.c",
        #"freeglut/freeglut/src/egl/fg_structure_egl.c",
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
        "@x11",
    ],
)
