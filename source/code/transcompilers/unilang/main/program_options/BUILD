package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "@com_github_boost_program_options//:program_options",
],
    linkopts = ["-lboost_program_options"],
)
