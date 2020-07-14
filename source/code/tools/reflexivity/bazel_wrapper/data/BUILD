package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "bazel_version_info",
    deps = [
    ],
)

hcp(
    name = "bazel_wrapper_refresh_settings",
    deps = [
        "//code/tools/reflexivity/bazel_wrapper/data:bazel_version_info",
    ],
)

hcp(
    name = "bazel_wrapper_refresh_settings_getter",
    deps = [
        ":bazel_wrapper_refresh_settings",
    ],
)
