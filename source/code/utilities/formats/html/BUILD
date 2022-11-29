package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "basic_html_template_getter",
    deps = [
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/formats/html:basic_html_template_settings",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/vectors/creators:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "basic_html_template_settings",
    deps = [],
)
