package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "mjkimage",
   hdrs = ["mjkimage.hpp"],
)

cc_binary(
    name = "sift",
    srcs = ["sift.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "@x11",
        "@glut",
        ":mjkimage",
    ],
)

cc_binary(
    name = "warp",
    srcs = ["warp.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "@x11",
        "@glut",
        ":mjkimage",
    ],
)

