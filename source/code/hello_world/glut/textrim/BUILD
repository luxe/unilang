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
        "@GL",
        "//code/utilities/formats/sgi:load_rgb",
        "@glut",
        "@mesa_glu",
        "@x11",
    ],
)
