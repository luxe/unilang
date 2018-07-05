package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

cpp_object(name = "bazel_build_object")

hcp(name = "bazel_load_data", deps = [
"//code/transcompilers/unilang/options/bazel:bazel_build_object"
])

hcp(name = "bazel_load_db_settings", deps = [
"//code/transcompilers/unilang/options/bazel:bazel_load_data"
])

hcp(name = "build_rule_settings", deps = [
"//code/transcompilers/unilang/options/bazel:bazel_load_db_settings"
])