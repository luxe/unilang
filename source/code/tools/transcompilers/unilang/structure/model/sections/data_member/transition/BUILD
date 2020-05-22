package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "value_transition_meaning",
    deps = [
        "data_member_transition_state",
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "data_member_transition_state",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)
