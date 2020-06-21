package(
    default_visibility = ["//visibility:public"],
)

filegroup(
    name = "data",
    srcs = glob([
        "*.cset",
    ]),
)

cc_library(
    name = "walkviewer",
    hdrs = ["walkviewer.hpp",],
    srcs = ["walkviewer.cpp",],
    deps = [
        "@glut",
        "@x11",
    ],
)

cc_library(
    name = "walker",
    hdrs = [
        "walker.hpp",
        "win32_dirent.hpp",
    ],
    deps = [
        "@glut",
        "@x11",
        ":walkviewer",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "models.cpp",
        "walker.cpp",
    ],
    data = [
        ":data",
    ],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":walker",
        ":walkviewer",
        "@glut",
        "@x11",
    ],
)
