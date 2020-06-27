package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp", "sphere.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "@x11",
        "@glut",
    ],
)
