package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/utilities/data_structures:index_mode",
        "//code/utilities/data_structures/index:moded_index",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/language_basic/std_hackery:std_aliases",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/squeeze:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "@boost//:range",
    ],
)

hcp_hdrs_derive(
    name = "remove_duplicate_json_representations",
    interface_deps = [
        "//code/utilities/data_structures:index_mode",
        "//code/utilities/data_structures/index:moded_index",
        "//code/utilities/language_basic/std_hackery:std_aliases",
        "//code/utilities/types/map:lib",
        "//code/utilities/types/sets:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/other:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/squeeze:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/formats/json/converters:type_to_json_string",
    ],
)
