package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "mime_xml_creator",
    deps = [
        "//code/utilities/system/mime:mime_xml_creation_settings",
        "//code/utilities/types/strings/creators:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "mime_xml_creation_settings",
    deps = [
    ],
)
