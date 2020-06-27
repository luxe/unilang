package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "add_fog",
    hdrs = [
        "addfog.hpp",
    ],
    srcs = [
        "addfog.cpp",
    ],
)

cc_binary(
    name = "depthcue",
    srcs = [
        "depthcue.cpp",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":add_fog",
        "@glut",
        "@x11",
    ],
)

cc_binary(
    name = "teapots",
    srcs = [
        "teapots.cpp",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":add_fog",
        "@glut",
        "@x11",
    ],
)
