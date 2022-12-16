package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(name = "token_method_argument_attribute_settings")

hcp_hdrs_derive(
    name = "token_method_attribute_settings",
    interface_deps = [
        "token_method_argument_attribute_settings",
        "token_method_inheritance_attribute_settings",
        "//code/utilities/code/properties/symbols/shared:token_access_attribute_settings",
    ],
)

hcp_hdrs_derive(name = "token_method_inheritance_attribute_settings")

hcp_hdrs_derive(name = "token_method_name_special_name_meaning")
