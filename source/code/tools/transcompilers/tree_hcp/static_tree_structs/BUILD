package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
hcp(
    name = "structs_creator",
    deps = [
        "//code/tools/transcompilers/hcp-compiler/programatic/data:function",
        "//code/utilities/data_structures/tree/generic:string_tree",
        "//code/utilities/data_structures/tree/generic:string_to_string_tree",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/tools/transcompilers/hcp-compiler/programatic/data:code",
        "//code/tools/transcompilers/hcp-compiler/programatic:code_getter",
        "//code/utilities/types/strings/transformers/wrap:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/tree:shortest_unique_name",
        "//code/utilities/types/tree/converters:tree_full_paths_getter",
        "//code/utilities/types/tree:children_path_names",
        "//code/utilities/types/strings/transformers/search_replace:lib",
    ],
)

cc_binary(
    name = "static_tree_structs",
    srcs = ["main.cpp"],
    deps = [
        ":structs_creator",
        "//code/tools/transcompilers/tree_hcp/static_tree_structs/program_options:lib",
        "//code/utilities/program/common_actions/locale:lib",
    ],
)
