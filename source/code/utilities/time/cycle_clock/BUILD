package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "cycle_clock")

hcp(
    name = "cycle_clock_checker",
    deps = [
        "//code/utilities/deps/external/imgui:lib",
        "//code/utilities/time/cycle_clock",
    ],
)
