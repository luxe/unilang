package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "izoom",
    srcs = ["izoom.cpp"],
    hdrs = ["izoom.hpp"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        ":izoom",
        "@glut",
        "@x11",
        "//code/utilities/formats/sgi:load_rgb"
    ],
)
