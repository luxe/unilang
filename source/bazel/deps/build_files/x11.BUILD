package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "x11",
    srcs = glob(
        [
            #"src/**/*.h",
            "src/**/*.c",
            "modules/**/*.c",
        ],
        exclude = [
            "src/os2Stubs.c",
            #"src/xlibi18n/lcInit.c",
            #"src/xlibi18n/lcWrap.c",
            #"src/Xrm.c",
            #"src/KeyBind.c",
            #"src/Font.c",
            #"src/LoadFont.c",
            #"src/xkb/XKBBind.c",
        ],
    ),
    hdrs = glob([
        "src/config.h",
        "include/X11/*.h",
        "src/**/*.h",
        "include/**/*.h",
        "**/*.h",
    ]),
    copts = [
        "-DXLOCALELIBDIR=\\\"/usr/local/lib/X11/locale\\\"",
        "-DHAVE_SYS_IOCTL_H",
        "-DXCMSDIR=\\\"FOO\\\"",
        "-DHAVE_CONFIG_H",
        #"-DUSE_DYNAMIC_LC",
    ],
    includes = [
        ".",
        "X11",
        "X11/Xtrans/",
        "include/X11",
        "src",
        "src/xcms",
        "src/xkb",
        "src/xlibi18n",
    ],
    linkstatic = True,
    deps = [
        "@Xau",
        "@Xaw",
        "@Xtrans",
        "@xcb",
        "@xkbcommon",
        "@xorg_libXext",
        "@xorg_libXi",
        "@xorg_libXt",
    ],
)
