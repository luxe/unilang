package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "gcal_getter",
    interface_deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/web:lib",
        "//code/utilities/web/endpoints/gcal:gcal_credentials",
        "//code/utilities/web/endpoints/gcal:gcal_query",
        "//code/utilities/web/endpoints/gcal/data:gcal_room",
        "//code/utilities/web/endpoints/gcal/data:gcal_rooms",
    ],
)

hcp_hdrs_derive(
    name = "gcal_query",
    interface_deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/web:lib",
        "//code/utilities/web/endpoints/gcal:gcal_credentials",
    ],
)

hcp_hdrs_derive(
    name = "gcal_credentials",
    interface_deps = [
    ],
)
