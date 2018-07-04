package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "structure_inliner", deps = [
"//code/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/parser:parser_settings",
"//code/transcompilers/unilang/parser:parser",
"//code/transcompilers/unilang/user-frontend/compiler:compiler",
"//code/transcompilers/unilang/user-frontend:exception_handler",
"//code/transcompilers/unilang/user-frontend:dependency_path_validator",
"//code/transcompilers/unilang/parser:structure_creator",
"//code/transcompilers/unilang/parser:parser_shared",
"//code/utilities/converters:lib",
"//code/utilities/filesystem/files/observers/lstat_wrap:lib",
])

hcp(name = "code_graph_adjuster", deps = [
"//code/transcompilers/unilang/main/program_options:lib",
"//code/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/main/root_settings:root_settings",
"//code/transcompilers/unilang/main/composed_program_options:composed_program_options",
"//code/transcompilers/unilang/validators/file_name:filename_validator",
"//code/transcompilers/unilang/parser:parser",
"//code/transcompilers/unilang/user-frontend/compiler:compiler",
"//code/transcompilers/unilang/user-frontend:exception_handler",
"//code/transcompilers/unilang/user-frontend/graph_adjuster:structure_inliner",
])