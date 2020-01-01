package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "value_transition_meaning", deps = [
"//code/tools/transcompilers/unilang/parser:token_value",
"data_member_transition_state"
])

hcp(name = "data_member_transition_state", deps = [
"//code/tools/transcompilers/unilang/parser:token_value"
])