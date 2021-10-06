package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "language_type",
    deps = [
        "//code/utilities/linguistics/computer/types/cross/language_type:language_type_category",
        "//code/utilities/linguistics/computer/types/cross/language_type:needed_import",
        "//code/utilities/linguistics/computer/types/cross/language_type:type_size",
    ],
)

hcp(
    name = "needed_import",
    deps = [
        "type_size",
        "//code/utilities/code:import_type",
    ],
)

hcp(
    name = "type_size",
    deps = [
    ],
)

enum_cpp(
    name = "language_type_category",
    values =
        [
            "fundamental",
            "abstract",
        ],
)
