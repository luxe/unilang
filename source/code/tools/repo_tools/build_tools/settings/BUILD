package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "settings", deps = [
    "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper",
    "//code/utilities/program/wrappers/git/repo_establisher:repo_location",
    "//code/utilities/program/wrappers/bazel:build_settings",
    "//code/utilities/program/wrappers/bazel/setup/config:bazel_config_settings",
    "//code/utilities/program/wrappers/bazel/setup:bazel_setup",
])


hcp(name = "settings_getter", deps = [
    "//code/tools/repo_tools/build_tools/settings:settings",
    "//code/tools/repo_tools/build_tools/program_options:lib",
])