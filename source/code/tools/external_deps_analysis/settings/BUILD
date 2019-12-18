package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "settings", deps = [
])

hcp(name = "settings_getter", deps = [
    "//code/tools/external_deps_analysis/settings:settings"
    "//code/tools/external_deps_analysis/program_options:program_options",
])