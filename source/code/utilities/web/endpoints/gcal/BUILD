package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "gcal_getter",
    deps = [
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

hcp(
    name = "gcal_query",
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/web:lib",
        "//code/utilities/web/endpoints/gcal:gcal_credentials",
    ],
)

hcp(
    name = "gcal_credentials",
    deps = [
    ],
)
