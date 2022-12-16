package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "global_event_listener",
    interface_deps = [
        "//code/utilities/deps/external/x11:lib",
        "//code/utilities/graphics/x11/data:main_x11_state",
        "//code/utilities/deps/external/xorg_xinput:lib",
    ],
)
