package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "contributor",
    deps = [
        "//code/utilities/contributor/appearance:contributor_appearance",
        "//code/utilities/contributor/contact:contributor_contact_details",
        "//code/utilities/contributor/names:contributor_names",
        "//code/utilities/contributor/work_info:contributor_work_info",
    ],
)
