package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
        #"-lglut",
    ],
    deps = [
        "@x11",
        "@glut",
    ],
)
