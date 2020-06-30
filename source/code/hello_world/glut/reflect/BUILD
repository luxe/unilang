package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "image",
    srcs = ["image.c"],
    hdrs = ["image.h"],
)

filegroup(
    name = "brick",
    srcs = ["brick.rgb"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    data = [":brick"],
    linkopts = [
        "-lGL",
        #"-lX11",
        #"-lglut",
        #"-lglut",
    ],
    deps = [
        "@GL",
        ":image",
        "@glut",
        "@x11",
    ],
)
