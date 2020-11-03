package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "structure_inliner",
    deps = [
        "//code/tools/transcompilers/old_unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/old_unilang/parser",
        "//code/tools/transcompilers/old_unilang/parser:parser_shared",
        "//code/tools/transcompilers/old_unilang/parser:structure_creator",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/tools/transcompilers/old_unilang/user-frontend:dependency_path_validator",
        "//code/tools/transcompilers/old_unilang/user-frontend:exception_handler",
        "//code/tools/transcompilers/old_unilang/user-frontend/command_line_arguments:dependency_paths",
        "//code/tools/transcompilers/old_unilang/user-frontend/compiler",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/types/converters:lib",
    ],
)

hcp(
    name = "code_graph_adjuster",
    deps = [
        "//code/tools/transcompilers/old_unilang/dependency_graph_creator:code_graph",
        "//code/tools/transcompilers/old_unilang/main/composed_program_options",
        "//code/tools/transcompilers/old_unilang/main/program_options:lib",
        "//code/tools/transcompilers/old_unilang/main/root_settings",
        "//code/tools/transcompilers/old_unilang/parser",
        "//code/tools/transcompilers/old_unilang/user-frontend:exception_handler",
        "//code/tools/transcompilers/old_unilang/user-frontend/command_line_arguments:dependency_paths",
        "//code/tools/transcompilers/old_unilang/user-frontend/compiler",
        "//code/tools/transcompilers/old_unilang/user-frontend/graph_adjuster:structure_inliner",
        "//code/tools/transcompilers/old_unilang/validators/file_name:filename_validator",
    ],
)
