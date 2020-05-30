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
    name = "libXpm_headers",
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
        "src/amigax.c",
    ],
)

cc_library(
    name = "libXpm",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        "include",
        "include/X11",
        "src",
    ],
    deps = [
        ":libXpm_headers",
    ],
)
