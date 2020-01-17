package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "scan_results", deps = [
    "//code/tools/repo_tools/build_determinism/scans/environment_scan:environment_scan_results",
    "//code/tools/repo_tools/build_determinism/scans/augment_scan:augment_scan_results",
])

hcp(name = "scan_results_printer", deps = [
    "//code/tools/repo_tools/build_determinism/settings:settings_getter",
    "//code/tools/repo_tools/build_determinism/scans:scan_results",
    "//code/tools/repo_tools/build_determinism:scan_utilities",
    "//code/utilities/printers:lib",
])