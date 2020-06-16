package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "trackball",
    hdrs = ["trackball.hpp"],
    srcs = ["trackball.cpp"]
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
        ":trackball",
    ],
)
