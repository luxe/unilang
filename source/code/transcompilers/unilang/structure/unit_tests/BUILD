package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "unit_tests", deps = [
"//code/transcompilers/unilang/structure/unit_tests:test_case",
])

hcp(name = "test_case", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/unit_tests:test_failure_reason",
])

hcp(name = "test_failure_reason", deps = [
"//code/transcompilers/unilang/parser:token_value",
])