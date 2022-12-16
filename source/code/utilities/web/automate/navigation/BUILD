package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "browser_navigator",
    interface_deps = [
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/time/sleeping:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/squeeze:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/web:lib",
        "//code/utilities/web/automate/browser:browser_settings",
        "//code/utilities/deps/external/pybind11:lib",
    ],
)
