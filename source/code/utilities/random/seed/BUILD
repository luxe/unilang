package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "start_seed_settings",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "start_seed_getter",
    interface_deps = [
        "//code/utilities/time/date:lib",
        "//code/utilities/types/strings/transformers/binary:lib",
        "//code/utilities/random/seed:start_seed_settings",
    ],
)
