package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
        "sphere.cpp",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "//code/utilities/graphics/opengl:sphere",
        "@glut",
        "@x11",
    ],
)
