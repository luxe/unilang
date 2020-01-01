package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "unit_tests", deps = [
"//code/tools/transcompilers/unilang/structure/model/unit_tests:test_case",
])

hcp(name = "test_case", deps = [
"//code/tools/transcompilers/unilang/parser:token_value",
"//code/tools/transcompilers/unilang/structure/model/unit_tests:test_failure_reason",
"//code/tools/transcompilers/unilang/structure/model/unit_tests:aaa_bodies",
])

hcp(name = "test_failure_reason", deps = [
"//code/tools/transcompilers/unilang/parser:token_value",
])

hcp(name = "aaa_bodies", deps = [
"//code/tools/transcompilers/unilang/parser:token_value",
])