
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
        "@x11",
        "@mesa_glu",
        "@glut",
        "//code/utilities/graphics/opengl:real_time_shadowing"
    ],
)