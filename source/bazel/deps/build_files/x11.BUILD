package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "x11",
    hdrs = glob([
        "src/config.h",
        "include/X11/*.h",
    ]),
    srcs = glob([
        "src/**/*.h",
        "src/**/*.c",
    ],
    exclude = [
        "src/os2Stubs.c",
    ]),
    copts = [
        "-DXLOCALELIBDIR=\\\"/usr/local/lib/X11/locale\\\"",
        "-DHAVE_SYS_IOCTL_H",
    ],
    includes = [
        "include/X11",
        "src",
        "src/xcms",
        "src/xlibi18n",
    ],
    linkstatic = True,
    deps = ["@xkbcommon//:xkbcommon"],
)