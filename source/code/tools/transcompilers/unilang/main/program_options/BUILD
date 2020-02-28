package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "@boost//:program_options",
        "//code/utilities/formats/artifact:artifact_type",
        "//code/tools/transcompilers/unilang/options/compiler:chosen_exporter"
    ],
)
