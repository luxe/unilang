package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "settings", deps = [
    "//code/utilities/bazel/setup/wrapper:bazel_wrapper",
    "//code/utilities/git-related/repo_establisher:repo_location",
    "//code/tools/repo_tools/build_determinism/settings:report_settings",
    "//code/utilities/data_structures:concurrency",
    "//code/utilities/bazel:build_settings",
    "//code/utilities/bazel/setup:bazel_setup",
])

hcp(name = "report_settings", deps = [
])

hcp(name = "settings_getter", deps = [
    "//code/tools/repo_tools/build_determinism/settings:settings",
    "//code/tools/repo_tools/build_determinism/program_options:lib",
    "//code/utilities/bazel/setup/wrapper:bazel_wrapper",
])
