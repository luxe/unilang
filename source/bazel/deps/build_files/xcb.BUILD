package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "xcb/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "xcb/*.c",
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
        "xcb/xcb",
    ],
    #strip_include_prefix = "src",
    #include_prefix = "xcb",
    deps = [
    ],
)
