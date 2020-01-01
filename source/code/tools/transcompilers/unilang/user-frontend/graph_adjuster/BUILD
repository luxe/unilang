package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "structure_inliner", deps = [
"//code/tools/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/parser:parser_settings",
"//code/tools/transcompilers/unilang/parser:parser",
"//code/tools/transcompilers/unilang/user-frontend/compiler:compiler",
"//code/tools/transcompilers/unilang/user-frontend:exception_handler",
"//code/tools/transcompilers/unilang/user-frontend:dependency_path_validator",
"//code/tools/transcompilers/unilang/parser:structure_creator",
"//code/tools/transcompilers/unilang/parser:parser_shared",
"//code/utilities/converters:lib",
"//code/utilities/filesystem/files/observers/lstat_wrap:lib",
])

hcp(name = "code_graph_adjuster", deps = [
"//code/tools/transcompilers/unilang/main/program_options:lib",
"//code/tools/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/main/root_settings:root_settings",
"//code/tools/transcompilers/unilang/main/composed_program_options:composed_program_options",
"//code/tools/transcompilers/unilang/validators/file_name:filename_validator",
"//code/tools/transcompilers/unilang/parser:parser",
"//code/tools/transcompilers/unilang/user-frontend/compiler:compiler",
"//code/tools/transcompilers/unilang/user-frontend:exception_handler",
"//code/tools/transcompilers/unilang/user-frontend/graph_adjuster:structure_inliner",
])