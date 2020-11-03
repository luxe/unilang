package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "macro_resolver",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/parser:macro_resolving_settings",
        "//code/tools/transcompilers/old_unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/old_unilang/parser:parser_token",
        "//code/tools/transcompilers/old_unilang/tokens:get_tokens",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
    ],
)

hcp(
    name = "parser",
    deps = [
        "//code/tools/transcompilers/old_unilang/dependency_graph_creator",
        "//code/tools/transcompilers/old_unilang/dependency_graph_creator:code_graph",
        "//code/tools/transcompilers/old_unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/old_unilang/parser:parser_shared",
        "//code/tools/transcompilers/old_unilang/parser:structure_creator",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/tools/transcompilers/old_unilang/user-frontend:fully_read_file",
        "//code/tools/transcompilers/old_unilang/user-frontend/command_line_arguments:dependency_paths",
    ],
)

hcp(
    name = "structure_creator",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/old_unilang/parser:macro_resolver",
        "//code/tools/transcompilers/old_unilang/parser:macro_warner",
        "//code/tools/transcompilers/old_unilang/parser:parser_token",
        "//code/tools/transcompilers/old_unilang/parser/structure_mapper:code_object_creator",
        "//code/tools/transcompilers/old_unilang/parser/tokenizer",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/tools/transcompilers/old_unilang/user-frontend:fully_read_file",
        "//code/tools/transcompilers/old_unilang/validators/stream:token_stream_validator",
    ],
)

hcp(
    name = "parser_shared",
    deps = [
        "//code/tools/transcompilers/old_unilang/user-frontend/command_line_arguments:dependency_paths",
        "//code/utilities/filesystem/paths:lib",
    ],
)

hcp(
    name = "macro_warner",
    deps = ["parser_token"],
)

hcp(
    name = "parser_token",
    deps = [
        "//code/tools/transcompilers/old_unilang/parser/body_parser:file_range_location",
        "//code/tools/transcompilers/old_unilang/parser/tokenizer/file_marker",
        "//code/tools/transcompilers/old_unilang/tokens:generic_token",
    ],
)

hcp(
    name = "global_tokens_table_utilities",
    deps = [
        "//code/tools/transcompilers/old_unilang/tokens:all_language_tokens",
        "//code/tools/transcompilers/old_unilang/tokens:generic_token",
        "//code/tools/transcompilers/old_unilang/tokens:get_tokens",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "token_value",
    deps = [
        "//code/tools/transcompilers/old_unilang/parser/body_parser:file_range_location",
        "//code/tools/transcompilers/old_unilang/tokens:token_name",
    ],
)
