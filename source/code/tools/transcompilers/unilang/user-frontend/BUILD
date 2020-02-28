package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "fully_read_file", deps = [
"//code/utilities/streams/filestreams/read_all:lib"
])

hcp(name = "actionable_code_graphs_creator", deps = [
"//code/tools/transcompilers/unilang/main:program_input",
"//code/tools/transcompilers/unilang/user-frontend/action_graphs:actionable_code_graphs",
"//code/tools/transcompilers/unilang/user-frontend:code_graphs_creator",
"//code/tools/transcompilers/unilang/user-frontend/action_graphs:code_graphs_to_actionable_graphs",
])

hcp(name = "exception_handler", deps = [
"//code/tools/transcompilers/unilang/parser/tokenizer/file_marker:file_marker",
"//code/tools/transcompilers/unilang/validators/file_name:filename_exception",
"//code/tools/transcompilers/unilang/parser/tokenizer:tokenizer_exception",
"//code/tools/transcompilers/unilang/validators/stream:token_stream_validation_exception",
"//code/utilities/language_basic/std_hackery:lib",
"//code/utilities/colors:lib",
])

hcp(name = "dependency_path_validator", deps = [
"//code/tools/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/utilities/filesystem/paths:lib",
])

hcp(name = "user_frontend", deps = [
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/main:program_input",
"//code/tools/transcompilers/unilang/user-frontend:program_input_enricher",
"//code/tools/transcompilers/unilang/user-frontend:actionable_code_graphs_creator",
"//code/tools/transcompilers/unilang/user-frontend:workspace_adjuster",
"//code/tools/transcompilers/unilang/user-frontend:transcompiler",
"//code/tools/transcompilers/unilang/user-frontend:after_artifact_actions",
"//code/tools/transcompilers/unilang/user-frontend/action_graphs:code_graphs_to_actionable_graphs",
"//code/tools/transcompilers/unilang/user-frontend/action_graphs:actionable_code_graphs",
])

hcp(name = "code_graphs_creator", deps = [
"//code/tools/transcompilers/unilang/user-frontend:fully_read_file",
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/main:program_input",
"//code/tools/transcompilers/unilang/validators/file_name:filename_validator",
"//code/tools/transcompilers/unilang/parser:parser",
"//code/tools/transcompilers/unilang/user-frontend/graph_adjuster:code_graph_adjuster",
"//code/tools/transcompilers/unilang/structure/analyze:structure_static_analyzer",
"//code/utilities/types/strings/transformers/stripping:lib",
])

hcp(name = "program_input_enricher", deps = [
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/main:program_input",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/general:lib",
"//code/utilities/filesystem/files/getting:lib",
"//code/utilities/program/common_actions/exits:lib",
"//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_guesser",
"//code/utilities/output/diagnostic:diagnostic_printer",
])

hcp(name = "transcompiler", deps = [
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/main:program_input",
"//code/tools/transcompilers/unilang/user-frontend/compiler:compiler",
"//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_guesser",
"//code/tools/transcompilers/unilang/user-frontend/action_graphs:actionable_code_graphs",
])

hcp(name = "after_artifact_actions", deps = [
"//code/tools/transcompilers/unilang/main/program_options:lib",
"//code/tools/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/main/root_settings:root_settings",
"//code/tools/transcompilers/unilang/main/composed_program_options:composed_program_options",
"//code/tools/transcompilers/unilang/user-frontend/graph_adjuster:code_graph_adjuster",
"//code/tools/transcompilers/unilang/user-frontend:fully_read_file",
"//code/tools/transcompilers/unilang/validators/file_name:filename_validator",
"//code/tools/transcompilers/unilang/parser:parser",
"//code/tools/transcompilers/unilang/user-frontend/compiler:compiler",
"//code/tools/transcompilers/unilang/user-frontend:exception_handler",
"//code/utilities/types/general:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/tools/transcompilers/unilang/structure/analyze:structure_static_analyzer",
"//code/utilities/filesystem/files/getting:lib",
"//code/tools/transcompilers/unilang/main:program_input",
"//code/utilities/program/common_actions/exits:lib",
"//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_guesser",
"//code/tools/transcompilers/unilang/user-frontend:workspace_adjuster",
"//code/tools/transcompilers/unilang/compiler-frontends/hidl:hidl_options_getter",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler:bazel_options_getter",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler:f2si_contributors_getter",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler:uber_contributors_getter",
"//code/tools/transcompilers/unilang/compiler-frontends/cpp:cpp_options_getter",
"//code/utilities/types/vectors/operators:lib",
"//code/utilities/program/call:lib",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler:file_transfer_settings_getter",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler:file_transferer",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/colors:lib",
"//code/tools/transcompilers/unilang/compiler-frontends/plant_uml_exporter:plant_uml_options_getter",
"//code/tools/transcompilers/unilang/compiler-frontends/html_table:html_table_options_getter",
"//code/utilities/output/diagnostic:diagnostic_printer",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_action_getter",
"//code/utilities/filesystem/paths:lib",
])


hcp(name = "file_to_structure_converter", deps = [
    "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
    "//code/tools/transcompilers/unilang/main/root_settings:root_settings_getter",
    "//code/tools/transcompilers/unilang/user-frontend:code_graphs_creator",
    "//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
    "//code/utilities/types/general:lib",
    "//code/utilities/program/common_actions/exits:lib",
])

hcp(name = "language_guesser", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/utilities/formats/artifact:artifact_type",
])

hcp(name = "workspace_adjuster", deps = [
"//code/tools/transcompilers/unilang/main:program_input",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/general:lib",
"//code/utilities/filesystem/files/getting:lib",
])