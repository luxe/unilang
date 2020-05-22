package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hiberlite",
    srcs = glob([
        "include/**/*.cpp",
    ]),
    hdrs = glob([
        "include/**/*.h",
        "include/**/*.hpp",
    ]),
    copts = [
        "-Wno-everything",
    ],
    includes = ["include"],
    deps = [
        "@sqlite3",
    ],
)
