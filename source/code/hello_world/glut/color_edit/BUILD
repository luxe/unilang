package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "hdrs",
    hdrs = ["mallocbis.h","RGBA.h"],
)

cc_binary(
    name = "main",
    srcs = [
        "Editor.c",
        "invertmat.c",
    ],
    data = [
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "@glut",
        "@x11",
        ":hdrs",
    ],
)
