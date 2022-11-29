package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "x11_bg_fg_colors",
    deps = [
        "//code/utilities/deps/external/x11:lib",
    ],
)

hcp(
    name = "x11_window_geometry",
    deps = [
        "//code/utilities/deps/external/x11:lib",
    ],
)

hcp(
    name = "main_x11_state",
    deps = [
        ":x11_bg_fg_colors",
        ":x11_window_geometry",
        "//code/utilities/deps/external/x11:lib",
    ],
)
