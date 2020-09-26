package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "software_law",
    deps = [],
)

hcp(
    name = "software_laws",
    deps = [":software_law"],
)

hcp(
    name = "get_software_laws",
    deps = [":software_laws"],
)
