package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

cpp_object(
    name = "tree_json_converters",
    deps = [
        "//code/utilities/deps/external/tree_hh:lib",
        "//code/utilities/types/tree/converters:depth_list",
        "@nlohmann_json",
    ],
)

cpp_object(
    name = "variant_json_converters",
    deps = [
        "@nlohmann_json",
    ],
)

cpp_object(
    name = "chrono_json_converters",
    deps = [
        "@nlohmann_json",
    ],
)
