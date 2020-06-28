package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "data",
    srcs = glob([
        "*.bw",
    ]),
)

cc_library(
    name = "textmap",
    hdrs = [
        "textmap.hpp",
    ],
    srcs = [
        "textmap.cpp",
    ],
    deps = [
        "//code/utilities/formats/sgi:load_rgb",
        "@glut",
        "@x11",
        "@mesa_glu",
    ]
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":textmap",
        "@glut",
        "@x11",
        "@mesa_glu",
    ],
    data = [":data"]
)
