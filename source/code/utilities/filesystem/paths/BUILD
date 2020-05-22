package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/program/call:lib",
        "@boost//:filesystem",
        "@boost//:range",
    ],
)

hcp(
    name = "path_getter",
    deps = [
        "//code/utilities/filesystem/paths:lib",
    ],
)

cpp_main(
    name = "path_to_desktop",
    deps = ["//code/utilities/filesystem/paths:lib"],
)

cpp_main(
    name = "current_path",
    deps = ["//code/utilities/filesystem/paths:lib"],
)

cpp_main(
    name = "bazel_workspace_directory",
    deps = ["//code/utilities/filesystem/paths:lib"],
)

cpp_main(
    name = "bazel_derived_root",
    deps = ["//code/utilities/filesystem/paths:lib"],
)
