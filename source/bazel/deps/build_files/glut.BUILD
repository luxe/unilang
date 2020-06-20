package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "include/**/*.h",
        "lib/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "lib/glut/**/*.c",
    ],
    exclude = [
        "lib/glut/win32_util.c",
        "lib/glut/win32_winproc.c",
        "lib/glut/win32_menu.c",
        "lib/glut/win32_glx.c",
        "lib/glut/win32_x11.c",
        "lib/glut/glut_wglext.c",
    ],
)

cc_library(
    name = "glut",
    srcs = srcs,
    hdrs = hdrs,
    includes = [
        "include",
        "lib/glut",
    ],
    deps = [
        "@mesa_glu",
        "@x11",
    ],
)
