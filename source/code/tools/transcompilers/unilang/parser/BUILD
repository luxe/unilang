package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "macro_resolver", deps = [
"//code/tools/transcompilers/unilang/parser:parser_token",
"//code/tools/transcompilers/unilang/options/parser:macro_resolving_settings",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/tools/transcompilers/unilang/tokens:get_tokens",
"//code/tools/transcompilers/unilang/options/parser:parser_settings"
])

hcp(name = "parser", deps = [
"//code/tools/transcompilers/unilang/parser:structure_creator",
"//code/tools/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/parser:parser_settings",
"//code/tools/transcompilers/unilang/parser:parser_shared",
"//code/tools/transcompilers/unilang/user-frontend:fully_read_file",
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/dependency_graph_creator:dependency_graph_creator",
])


hcp(name = "structure_creator", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/parser:parser_token",
"//code/tools/transcompilers/unilang/options/parser:parser_settings",
"//code/tools/transcompilers/unilang/user-frontend:fully_read_file",
"//code/tools/transcompilers/unilang/validators/stream:token_stream_validator",
"//code/tools/transcompilers/unilang/parser/tokenizer:tokenizer",
"//code/tools/transcompilers/unilang/parser:macro_warner",
"//code/tools/transcompilers/unilang/parser:macro_resolver",
"//code/tools/transcompilers/unilang/parser/structure_mapper:code_object_creator",
])

hcp(name = "parser_shared", deps = [
"//code/tools/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/utilities/filesystem/paths:lib"
])

hcp(name = "macro_warner", deps = ["parser_token"])

hcp(name = "parser_token", deps = [
"//code/tools/transcompilers/unilang/tokens:generic_token",
"//code/tools/transcompilers/unilang/parser/tokenizer/file_marker:file_marker",
"//code/tools/transcompilers/unilang/parser/body_parser:file_range_location",
])

hcp(name = "global_tokens_table_utilities", deps = [
"//code/tools/transcompilers/unilang/tokens:generic_token",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/vectors/operators:lib",
"//code/tools/transcompilers/unilang/tokens:get_tokens",
"//code/tools/transcompilers/unilang/tokens:all_language_tokens",
])

hcp(name = "token_value", deps = [
"//code/tools/transcompilers/unilang/parser/body_parser:file_range_location",
"//code/tools/transcompilers/unilang/tokens:token_name"
])
