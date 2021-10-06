package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "url_parser",
    interface_deps = [
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/deps/external/cxx_url:lib",
    ],
)

hcp_hdrs_derive(
    name = "github_url_getter",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "url_identifier",
    interface_deps = [
        "//code/utilities/types/strings/observers/other:lib",
    ],
)

hcp_hdrs_derive(
    name = "url_extractor",
    interface_deps = [
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/deps/stl/string:lib",
        "//code/utilities/deps/stl/regex:lib",
        "//code/utilities/deps/stl/set:lib",
    ],
)
