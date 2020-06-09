package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
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
    name = "xorg_libXrandr",
    srcs = srcs,
    hdrs = hdrs,
    includes = [
        "include",
        "src",
        "include/X11/extensions",
    ],
    deps = [],
)
