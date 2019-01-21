package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/unilang:generate_unilang_token_files.bzl", "generate_unilang_token_files")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
	name = "ast_markers",
	deps = ["//code/transcompilers/enum_cpp:enum"]
)
hcp(
	name = "all_ast_markers",
	deps = ["ast_markers"]
)
hcp(
	name = "all_ast_markers_getter",
	deps = ["all_ast_markers"]
)
hcp(
	name = "enum_printer",
	deps = ["all_ast_markers",
    "//code/utilities/streams/filestreams:lib",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/transcompilers/enum_cpp:enum_cpp_maker",
    ]
)

hcp(
	name = "task_executer",
	deps = ["all_ast_markers_getter","enum_printer"]
)

hcp(
    name = "as_vertex_graph",
    deps = ["//code/utilities/data_structures/unique_str_vertex_graph:lib"]
)

hcp(
    name = "all_language_tokens",
    deps = ["//code/transcompilers/unilang/tokens:generic_token",
    "//code/transcompilers/unilang/tokens:standalone_symbols",]
)

hcp(
    name = "standalone_symbols",
)

hcp(
    name = "get_tokens",
deps = [
    "//code/transcompilers/unilang/tokens:all_ast_markers",
    "//code/utilities/streams/filestreams:lib",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/transcompilers/unilang/tokens:generic_token",
    "//code/transcompilers/unilang/tokens:token_name",
    "//code/transcompilers/unilang/tokens:token_group",
    "//code/transcompilers/unilang/tokens:all_language_tokens",
]
)

cc_binary(
    name = "unilang_token_file_generator",
    srcs = ["main.cpp"],
    deps = ["task_executer","//code/utilities/types/strings/transformers/removing:lib"]
)

cc_binary(
    name = "print_token_tree",
    srcs = ["print_token_tree.cpp"],
    deps = ["as_vertex_graph"]
)

cpp_object(name="generic_token",deps=["//code/transcompilers/unilang/tokens:token_name","//code/transcompilers/unilang/tokens:token_group"])

generate_unilang_token_files()