package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cpp_object(name = "bazel_build_object")

hcp(name = "bazel_load_data", deps = [
"//code/transcompilers/unilang/options/bazel:bazel_build_object"
])

hcp(name = "bazel_load_db_settings", deps = [
"//code/transcompilers/unilang/options/bazel:bazel_load_data"
])

hcp(name = "build_rule_settings", deps = [
"//code/transcompilers/unilang/options/bazel:bazel_load_db_settings",
"//code/transcompilers/unilang/options/sections:portion_options",
])

hcp(name = "language_to_build_object", deps = [
"//code/transcompilers/unilang/options/bazel:bazel_build_object"
])
