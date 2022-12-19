package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "gcal_room",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "gcal_rooms",
    interface_deps = [
        "//code/utilities/web/endpoints/gcal/data:gcal_room",
    ],
)

hcp_hdrs_derive(
    name = "gcal_sorted_events",
    interface_deps = [
    ],
)
