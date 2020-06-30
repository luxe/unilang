package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "trackball",
    srcs = ["trackball.cpp"],
    hdrs = ["trackball.hpp"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "@GL",
        ":trackball",
        "@glut",
        "@mesa_glu",
        "@x11",
    ],
)
