package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "fully_read_file", deps = [
"//code/utilities/streams/filestreams/read_all:lib"
])

hcp(name = "exception_handler", deps = [
"//code/transcompilers/unilang/file_marker:file_marker",
"//code/transcompilers/unilang/validators/file_name:filename_exception",
"//code/transcompilers/unilang/tokenizer:tokenizer_exception",
"//code/transcompilers/unilang/validators/stream:token_stream_validation_exception",
"//code/utilities/std_hackery:lib",
"//code/utilities/colors:lib",
])

hcp(name = "dependency_path_validator", deps = [
"//code/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/utilities/filesystem/paths:lib",
])

hcp(name = "user_frontend", deps = [
"//code/transcompilers/unilang/main/program_options:lib",
"//code/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/main/root_settings:root_settings",
"//code/transcompilers/unilang/main/composed_program_options:composed_program_options",
"//code/transcompilers/unilang/user-frontend/graph_adjuster:code_graph_adjuster",
"//code/transcompilers/unilang/user-frontend:fully_read_file",
"//code/transcompilers/unilang/validators/file_name:filename_validator",
"//code/transcompilers/unilang/parser:parser",
"//code/transcompilers/unilang/user-frontend/compiler:compiler",
"//code/transcompilers/unilang/user-frontend:exception_handler",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/transcompilers/unilang/structure_static_analyzer:structure_static_analyzer",
"//code/utilities/filesystem/files/getting:lib",
"//code/transcompilers/unilang/main:program_input",
"//code/utilities/exits:lib",
"//code/transcompilers/unilang/user-frontend:language_guesser",
"//code/transcompilers/unilang/compiler-frontends/hidl:hidl_options_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:bazel_options_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_contributors_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:uber_contributors_getter",
"//code/transcompilers/unilang/compiler-frontends/cpp:cpp_options_getter",
"//code/utilities/types/vectors/operators:lib",
"//code/utilities/shell:lib",
"//code/transcompilers/unilang/f2si_frontend_compiler:file_transfer_settings_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:file_transferer",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/colors:lib",
"//code/transcompilers/unilang/compiler-frontends/plant_uml_exporter:plant_uml_options_getter",
"//code/transcompilers/unilang/compiler-frontends/html_table:html_table_options_getter",
"//code/utilities/diagnostic:diagnostic_printer",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_action_getter",
])

hcp(name = "language_guesser", deps = [
"//code/transcompilers/unilang/structure:structure",
])