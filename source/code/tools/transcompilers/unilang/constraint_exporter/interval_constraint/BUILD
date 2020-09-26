package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "interval_inclusion_type")

hcp(
    name = "interval_constraint",
    deps = [
        "//code/tools/transcompilers/unilang/constraint_exporter/interval_constraint:interval_point",
    ],
)

hcp(
    name = "interval_point",
    deps = [
        "//code/tools/transcompilers/unilang/constraint_exporter/interval_constraint:interval_inclusion_type",
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)
