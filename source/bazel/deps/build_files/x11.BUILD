package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "x11",
    srcs = glob(
        [
            "src/**/*.h",
            "src/**/*.c",
        ],
        exclude = [
            "src/os2Stubs.c",
        ],
    ),
    hdrs = glob([
        "src/config.h",
        "include/X11/*.h",
    ]),
    copts = [
        "-DXLOCALELIBDIR=\\\"/usr/local/lib/X11/locale\\\"",
        "-DHAVE_SYS_IOCTL_H",
        "-DXCMSDIR=\\\"FOO\\\"",
    ],
    includes = [
        "include/X11",
        "src",
        "src/xcms",
        "src/xlibi18n",
        "X11/Xtrans/",
        "X11",
        ".",
    ],
    linkstatic = True,
    deps = [
        "@xcb",
        "@xkbcommon",
        "@Xtrans"
    ],
)
