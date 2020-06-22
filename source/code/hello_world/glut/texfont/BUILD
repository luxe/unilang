package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "data",
    srcs = glob([
        "*.txf",
    ]),
)

cc_library(
    name = "texfont",
    hdrs = [
        "TexFont.h",
    ],
    srcs = ["texfont.c"],
    deps = [
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "demo",
    srcs = [
        "txfdemo.c",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":texfont",
        "@glut",
        "@x11",
    ],
)
