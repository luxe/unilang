package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "test_case", deps = [
"test_section",
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "test_section")

hcp(name = "unit_tests", deps = [
"test_case"
])