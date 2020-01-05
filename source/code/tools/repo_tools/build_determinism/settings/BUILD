package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "settings", deps = [
    "//code/utilities/bazel/wrapper:bazel_wrapper",
    "//code/utilities/git-related/repo_establisher:repo_location",
    "//code/tools/repo_tools/build_determinism/settings:report_settings",
    "//code/utilities/bazel:run_environment",
    "//code/utilities/data_structures:concurrency",
])

hcp(name = "report_settings", deps = [
])

hcp(name = "settings_getter", deps = [
    "//code/tools/repo_tools/build_determinism/settings:settings",
    "//code/tools/repo_tools/build_determinism/program_options:lib",
    "//code/utilities/bazel/wrapper:bazel_wrapper",
])