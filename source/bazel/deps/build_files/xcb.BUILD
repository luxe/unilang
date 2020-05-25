package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "xcb/src/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "xcb/src/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "xcb",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        "-DXCB_QUEUE_BUFFER_SIZE=16384",
        "-DIOV_MAX=16",
    ],
    includes = [
        ".",
        "src",
        "xcb",
        "xcb/src",
    ],
    include_prefix = "xcb",
    deps = [
    ],
)
