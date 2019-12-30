package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "settings", deps = [
    "//code/tools/repo_tools/build_determinism/settings:bazel_wrapper",
    "//code/tools/repo_tools/build_determinism/settings:repo_location",
    "//code/utilities/bazel:spawn_strategy",
])

hcp(name = "bazel_wrapper", deps = [
])
hcp(name = "repo_location", deps = [
])

hcp(name = "settings_getter", deps = [
    "//code/tools/repo_tools/build_determinism/settings:settings",
    "//code/tools/repo_tools/build_determinism/program_options:lib",
    "//code/tools/repo_tools/build_determinism/settings:bazel_wrapper",
])