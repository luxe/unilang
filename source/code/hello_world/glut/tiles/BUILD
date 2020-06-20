package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "tr",
    srcs = ["tr.cpp"],
    hdrs = ["tr.hpp"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = [
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":tr",
        "@glut",
        "@libXxf86vm",
        "@x11",
        "@xorg_libXext",
    ],
)
