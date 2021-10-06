package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "build_repo_settings",
    interface_deps = [
        "//code/utilities/program/wrappers/bazel:build_settings",
        "//code/utilities/program/wrappers/bazel/setup:bazel_setup",
        "//code/utilities/program/wrappers/git/repo_establisher:established_repo",
        "//code/utilities/program/wrappers/git/repo_establisher:repo_location",
    ],
)

hcp_hdrs_derive(
    name = "build_repo_establisher",
    implementation_deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/wrappers/bazel:default_build_settings",
        "//code/utilities/program/wrappers/bazel/setup:bazel_setup_deriver",
        "//code/utilities/program/wrappers/bazel/setup:default_bazel_setup_settings",
        "//code/utilities/program/wrappers/bazel/setup/config:bazel_config_deriver",
        "//code/utilities/program/wrappers/bazel/setup/wrapper:bazel_wrapper_deriver",
        "//code/utilities/program/wrappers/git/repo_establisher:repo_establisher",
        "//code/utilities/program/wrappers/git/repo_establisher:default_repo_location_getter",
        "//code/utilities/types/strings/observers/path:lib",
    ],
    interface_deps = [
        "//code/utilities/build/build_repo_establisher:build_repo_settings",
    ],
)
