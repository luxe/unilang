package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "fracviewer",
    hdrs = ["fracviewer.hpp"],
    srcs = ["fracviewer.cpp"],
    deps = [
        "@x11",
        "@glut",
        "@mesa_glu",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "@x11",
        "@glut",
        "@mesa_glu",
        ":fracviewer",
    ],
)
