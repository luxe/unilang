package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "file_extension_lookup_table",
    deps = [
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/file_extension/language_extensions",
    ],
)

hcp(
    name = "language_extension_deriver",
    deps = [
        "//code/utilities/linguistics/computer/file_extension/language_extensions",
    ],
)

hcp(
    name = "file_extension_lookup_table_getter",
    deps = [
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/linguistics/computer/file_extension/language_extensions",
        "//code/utilities/linguistics/computer/file_extension/lookup_table:file_extension_lookup_table",
        "//code/utilities/linguistics/computer/file_extension/lookup_table:language_extension_deriver",
        "//code/utilities/types/map:lib",
    ],
)
