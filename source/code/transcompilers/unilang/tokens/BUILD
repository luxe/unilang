package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","generate_unilang_token_files","cpp_object")

hcp(
	name = "enum"
)
hcp(
	name = "ast_markers",
	deps = ["enum"]
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
	deps = ["all_ast_markers","//code/utilities/streams/filestreams:lib","//code/utilities/types/strings/transformers/casing:lib"]
)

hcp(
	name = "task_executer",
	deps = ["all_ast_markers_getter","enum_printer"]
)

cc_binary(
    name = "unilang_token_file_generator",
    srcs = ["main.cpp"],
    deps = ["task_executer","//code/utilities/types/strings/transformers/removing:lib"]
)

cpp_object(name="generic_token",deps=["//code/transcompilers/unilang/tokens:token_name","//code/transcompilers/unilang/tokens:token_group"])

generate_unilang_token_files()