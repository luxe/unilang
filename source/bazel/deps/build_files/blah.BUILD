package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "include/**/*.h",
        "include/**/*.hpp",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "src/**/*.cpp",
        "src/**/*.c",
        "src/**/*.hpp",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

cc_library(
    name = "hdrs",
    hdrs = hdrs,
    includes = [
        ".",
        "include",
    ],
)

cc_library(
    name = "blah",
    srcs = srcs,
    includes = [
        ".",
        "src",
    ],
    deps = [
        ":hdrs",
    ],
)
