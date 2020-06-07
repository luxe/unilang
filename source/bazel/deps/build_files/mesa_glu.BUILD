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
        "src/**/*.cc",
    ],
    exclude = [
    ],
)

cc_library(
    name = "mesa_glu",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        ".",
        "include",
        "src",
    ],
    deps = [
    ],
)
