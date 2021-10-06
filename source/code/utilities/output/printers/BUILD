package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = ["@pretty_print//:lib"],
)

hcp_hdrs_derive(
    name = "terminal",
    implementation_deps = [
        "//code/utilities/types/strings/transformers/colors:string_colorizer",
    ],
)
