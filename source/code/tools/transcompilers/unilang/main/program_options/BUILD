package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/tools/transcompilers/unilang/options/compiler:chosen_exporter",
        "//code/utilities/formats/artifact:artifact_type",
        "@boost//:program_options",
    ],
)
