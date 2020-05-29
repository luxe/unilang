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
    name = "Xaw_headers",
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        ".",
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
    name = "Xaw",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
        "src",
    ],
    deps = [
        ":Xaw_headers",
        "@Xmu",
    ],
)
