package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(name = "artifact_type",
values = 
["c"
,"cpp"
,"cpp_test"
,"cpp_benchmark"
,"cpp_fuzz"
,"csharp"
,"d"
,"rust"
,"processing"
,"date"
,"bazel"
,"hidl"
,"protobuf"
,"plant_uml"
,"call_graph"
,"html_table"
,"treesheets"
,"graph_easy"
,"mermaid"
])

hcp(name = "fully_read_file", deps = [
"//code/utilities/streams/filestreams/read_all:lib"
])

hcp(name = "exception_handler", deps = [
"//code/transcompilers/unilang/parser/tokenizer/file_marker:file_marker",
"//code/transcompilers/unilang/validators/file_name:filename_exception",
"//code/transcompilers/unilang/parser/tokenizer:tokenizer_exception",
"//code/transcompilers/unilang/validators/stream:token_stream_validation_exception",
"//code/utilities/std_hackery:lib",
"//code/utilities/colors:lib",
])

hcp(name = "dependency_path_validator", deps = [
"//code/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/utilities/filesystem/paths:lib",
])

hcp(name = "user_frontend", deps = [
"//code/transcompilers/unilang/structure/model:inlined_structures",
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/main:program_input",
"//code/transcompilers/unilang/user-frontend:program_input_enricher",
"//code/transcompilers/unilang/user-frontend:code_graphs_creator",
"//code/transcompilers/unilang/user-frontend:workspace_adjuster",
"//code/transcompilers/unilang/user-frontend:transcompiler",
"//code/transcompilers/unilang/user-frontend:after_artifact_actions",
"//code/transcompilers/unilang/user-frontend/action_graphs:code_graphs_to_actionable_graphs",
])

hcp(name = "code_graphs_creator", deps = [
"//code/transcompilers/unilang/user-frontend:fully_read_file",
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/main:program_input",
"//code/transcompilers/unilang/validators/file_name:filename_validator",
"//code/transcompilers/unilang/parser:parser",
"//code/transcompilers/unilang/user-frontend/graph_adjuster:code_graph_adjuster",
"//code/transcompilers/unilang/structure/analyze:structure_static_analyzer",
"//code/utilities/types/strings/transformers/stripping:lib",
])

hcp(name = "program_input_enricher", deps = [
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/main:program_input",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/general:lib",
"//code/utilities/filesystem/files/getting:lib",
"//code/utilities/exits:lib",
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_guesser",
"//code/utilities/diagnostic:diagnostic_printer",
])

hcp(name = "transcompiler", deps = [
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/main:program_input",
"//code/transcompilers/unilang/user-frontend/compiler:compiler",
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_guesser",
])

hcp(name = "after_artifact_actions", deps = [
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
"//code/transcompilers/unilang/structure/analyze:structure_static_analyzer",
"//code/utilities/filesystem/files/getting:lib",
"//code/transcompilers/unilang/main:program_input",
"//code/utilities/exits:lib",
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_guesser",
"//code/transcompilers/unilang/user-frontend:workspace_adjuster",
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
"//code/utilities/filesystem/paths:lib",
])

hcp(name = "language_guesser", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_type",
])

hcp(name = "workspace_adjuster", deps = [
"//code/transcompilers/unilang/main:program_input",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/general:lib",
"//code/utilities/filesystem/files/getting:lib",
])