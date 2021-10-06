cc_library(
    name = "yaml-cpp",
    srcs = glob([
        "src/**/*.cpp",
        "src/**/*.h",
    ]),
    hdrs = glob(["include/yaml-cpp/**/*.h"]),
    copts = ["-Wno-everything"],
    includes = [
        "include",
        "src",
    ],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "parse",
    srcs = ["util/parse.cpp"],
    copts = ["-Wno-everything"],
    visibility = ["//visibility:public"],
    deps = [":yaml-cpp"],
)

cc_binary(
    name = "sandbox",
    srcs = ["util/sandbox.cpp"],
    copts = ["-Wno-everything"],
    visibility = ["//visibility:public"],
    deps = [":yaml-cpp"],
)

cc_binary(
    name = "read",
    srcs = ["util/read.cpp"],
    copts = ["-Wno-everything"],
    visibility = ["//visibility:public"],
    deps = [":yaml-cpp"],
)

cc_test(
    name = "yaml-cpp_test",
    srcs = glob([
        "test/*.cpp",
        "test/integration/*.cpp",
        "test/node/*.cpp",
        "test/new-api/*.cpp",
        "test/*.h",
        "test/integration/*.h",
    ]),
    includes = ["test"],
    deps = [
        ":yaml-cpp",
        "@com_google_googletest//:gtest",
    ],
)
