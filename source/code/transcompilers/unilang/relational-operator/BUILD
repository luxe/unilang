package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

cpp_object(name = "relational_operator")
hcp(name = "relational_operator_converter", deps = [
"//code/transcompilers/unilang/relational-operator:relational_operator"
])