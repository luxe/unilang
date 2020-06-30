package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "@GL",
        "//code/utilities/graphics/opengl:sphere",
        "@glut",
        "@x11",
    ],
)
