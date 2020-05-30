package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

cc_library(
    name = "Xorg_libSM_headers",
    hdrs = hdrs,
    copts = [
    ],
    deps = [
    ],
)

srcs = glob(
    include = [
        "src/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "xorg_libSM",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
        "include",
        "include/X11/SM",
        "src",
    ],
    deps = [
        ":Xorg_libSM_headers",
        "@xorg_libICE",
    ],
)
