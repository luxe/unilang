package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "glx_data",
    interface_deps = [
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/deps/external/gl:lib",
        "//code/utilities/deps/external/khr:lib",
    ],
)
