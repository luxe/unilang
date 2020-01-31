package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "augment_scan_results", deps = [
])

hcp(name = "augment_scanner", deps = [
    "//code/tools/repo_tools/build_determinism/settings:settings_getter",
    "//code/utilities/printers:lib",
    "//code/utilities/git-related/repo_establisher:repo_establisher",
    "//code/utilities/bazel/setup/wrapper:bazel_wrapper_deriver",
    "//code/tools/repo_tools/build_determinism:determinism_ab_runner",
    "//code/tools/repo_tools/build_determinism:reporter",
    "//code/tools/repo_tools/build_determinism:subcommand_filter",
    "//code/tools/repo_tools/build_determinism:determinism_problem_getter",
    "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
    "//code/utilities/random:lib",
    "//code/utilities/bazel:bazel_runner",
    "//code/utilities/filesystem/files/moving:lib",
    "//code/tools/repo_tools/build_determinism:file_isolator",
    "//code/tools/repo_tools/build_determinism/scans/augment_scan:augment_scan_results",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/tools/repo_tools/build_determinism:scan_utilities",
    "//code/tools/repo_tools/build_determinism/settings:ab_settings",
])
