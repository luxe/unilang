package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "@boost//:program_options",
        "//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_type",
        "//code/transcompilers/unilang/options/compiler:chosen_exporter"
    ],
)
