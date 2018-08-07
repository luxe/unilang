package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cpp_object(name = "interval_inclusion_type")

hcp(name = "interval_constraint", deps = [
"//code/transcompilers/unilang/constraint_exporter/interval_constraint:interval_point",
])

hcp(name = "interval_point", deps = [
"//code/transcompilers/unilang/constraint_exporter/interval_constraint:interval_inclusion_type",
"//code/transcompilers/unilang/parser:token_value",
])