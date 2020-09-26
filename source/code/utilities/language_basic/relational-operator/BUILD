package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "relational_operator")

hcp(
    name = "relational_operator_converter",
    deps = [
        "//code/utilities/language_basic/relational-operator:relational_operator",
        "//code/utilities/language_basic/relational-operator:relational_operator_print_settings",
    ],
)

hcp(name = "relational_operator_print_settings")
