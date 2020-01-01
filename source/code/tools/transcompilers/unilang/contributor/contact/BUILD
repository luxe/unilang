package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "email_address")
hcp(name = "phone_number")
hcp(name = "physical_address")
hcp(name = "contributor_contact_details", deps = [
"email_address",
"phone_number",
"physical_address"
])