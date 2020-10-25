package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "hcp_creator",
    deps = [
        "//code/tools/transcompilers/hcp-compiler/programatic:code_getter",
        "//code/tools/transcompilers/hcp-compiler/programatic/data:code",
        "//code/tools/transcompilers/hcp-compiler/programatic/data:function",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/wrap:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/data_structures/tree/generic:string_to_string_tree",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/tree:shortest_unique_name",
        "//code/utilities/types/tree:children_path_names",
        "//code/utilities/types/strings/observers/characteristic:is_cpp_keyword_checker",
        "//code/utilities/types/tree:first_full_path_name",
        "//code/tools/transcompilers/tree_hcp/shared:path_naming",
        "//code/tools/transcompilers/hcp-compiler/programatic/data:headers",
        "//code/utilities/types/strings/observers/path:lib",
    ],
)

cc_binary(
    name = "string_tree_to_static_tree_parser",
    srcs = ["main.cpp"],
    deps = [
        ":hcp_creator",
        "//code/tools/transcompilers/tree_hcp/string_tree_to_static_tree_parser/program_options:lib",
        "//code/utilities/program/common_actions/locale:lib",
    ],
)
