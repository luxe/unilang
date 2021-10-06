package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(name = "email_address")

hcp_hdrs_derive(name = "phone_number")

hcp_hdrs_derive(name = "physical_address")

hcp_hdrs_derive(
    name = "contributor_contact_details",
    interface_deps = [
        "email_address",
        "phone_number",
        "physical_address",
    ],
)
