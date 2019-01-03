package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "relational_operator")

hcp(name = "relational_operator_converter", deps = [
"//code/utilities/relational-operator:relational_operator",
"//code/utilities/relational-operator:relational_operator_print_settings",
])

hcp(name = "relational_operator_print_settings")