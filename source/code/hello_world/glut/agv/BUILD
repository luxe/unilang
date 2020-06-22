package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "agviewer",
    hdrs = ["agviewer.h",],
    srcs = ["agviewer.c",],
    deps = [
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "agv_example.c",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":agviewer",
        "@glut",
        "@x11",
    ],
)
