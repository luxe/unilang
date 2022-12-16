package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "token_attribute_settings",
    interface_deps = [
        "//code/utilities/code/properties/symbols:token_enumerated_attribute_settings",
        "//code/utilities/code/properties/symbols:token_inheritance_attribute_settings",
        "//code/utilities/code/properties/symbols:token_literature_settings",
        "//code/utilities/code/properties/symbols:token_macro_attribute_settings",
        "//code/utilities/code/properties/symbols:token_meta_attribute_settings",
        "//code/utilities/code/properties/symbols:token_namespace_attribute_settings",
        "//code/utilities/code/properties/symbols:token_typedef_attribute_settings",
        "//code/utilities/code/properties/symbols/data_member:token_data_member_attribute_settings",
        "//code/utilities/code/properties/symbols/import:token_import_attribute_settings",
        "//code/utilities/code/properties/symbols/method:token_method_attribute_settings",
    ],
)

hcp_hdrs_derive(
    name = "token_enumerated_attribute_settings",
    interface_deps = ["//code/utilities/code/properties/symbols/shared:token_access_attribute_settings"],
)

hcp_hdrs_derive(
    name = "token_inheritance_attribute_settings",
    interface_deps = ["//code/utilities/code/properties/symbols/shared:token_access_attribute_settings"],
)

hcp_hdrs_derive(
    name = "token_macro_attribute_settings",
    interface_deps = ["//code/utilities/code/properties/symbols/shared:token_access_attribute_settings"],
)

hcp_hdrs_derive(name = "token_meta_attribute_settings")

hcp_hdrs_derive(name = "token_namespace_attribute_settings")

hcp_hdrs_derive(name = "token_literature_settings")

hcp_hdrs_derive(
    name = "token_typedef_attribute_settings",
    interface_deps = ["//code/utilities/code/properties/symbols/shared:token_access_attribute_settings"],
)
