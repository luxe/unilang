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
    name = "Xmu_headers",
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
    name = "Xmu",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        "src",
        "include/X11/Xmu",
    ],
    deps = [
        ":Xmu_headers",
    ],
)
