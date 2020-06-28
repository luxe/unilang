package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "@glut",
        "@x11",
        "//code/utilities/formats/sgi:load_rgb"
    ],
)
