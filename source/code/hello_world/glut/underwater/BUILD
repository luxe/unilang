package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "dino",
    hdrs = [
        "dino.h",
    ],
    srcs = ["dino.c",],
    deps = [
        "@glut",
        "@x11",
    ],
)

cc_library(
    name = "texload",
    hdrs = [
        "texload.h",
    ],
    srcs = ["texload.c",],
    deps = [
        "@glut",
        "@x11",
    ],
)

filegroup(
    name = "data",
    srcs = [
        "floor.rgb",
    ] + glob([
        "*.bw",
    ]),
)

cc_binary(
    name = "main",
    srcs = [
        "underwater.c",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":dino",
        ":texload",
        "@glut",
        "@x11",
    ],
)
