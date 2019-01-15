package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "macro_resolver", deps = [
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/options/parser:macro_resolving_settings",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
])

hcp(name = "parser", deps = [
"//code/transcompilers/unilang/parser:structure_creator",
"//code/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/parser:parser_settings",
"//code/transcompilers/unilang/parser:parser_shared",
"//code/transcompilers/unilang/user-frontend:fully_read_file",
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/dependency_graph_creator:dependency_graph_creator",
])


hcp(name = "structure_creator", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/parser:parser_token",
"//code/transcompilers/unilang/options/parser:parser_settings",
"//code/transcompilers/unilang/user-frontend:fully_read_file",
"//code/transcompilers/unilang/validators/stream:token_stream_validator",
"//code/transcompilers/unilang/tokenizer:tokenizer",
"//code/transcompilers/unilang/parser:macro_warner",
"//code/transcompilers/unilang/parser:macro_resolver",
"//code/transcompilers/unilang/parser_tokens_to_structure_converter:code_object_creator",
])

hcp(name = "parser_shared", deps = [
"//code/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/utilities/filesystem/paths:lib"
])

hcp(name = "macro_warner", deps = ["parser_token"])

hcp(name = "parser_token", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/file_marker:file_marker",
"//code/transcompilers/unilang/parser/body_parser:file_range_location",
])

hcp(name = "global_tokens_table_utilities", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/vectors/operators:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
])

hcp(name = "token_value", deps = [
"//code/transcompilers/unilang/parser/body_parser:file_range_location",
"//code/transcompilers/unilang/tokens:token_name"
])
