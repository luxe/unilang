package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "compiler", deps = [
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/user-frontend/action_graphs:actionable_code_graph",
"//code/tools/transcompilers/unilang/user-frontend/action_graphs:actionable_code_graphs",
"//code/tools/transcompilers/unilang/main:program_input",
"//code/tools/transcompilers/unilang/compiler-frontends/hidl:hidl_options_getter",
"//code/tools/transcompilers/unilang/compiler-frontends/hidl:hidl_exporter",
"//code/tools/transcompilers/unilang/options/bazel:language_to_build_object",
"//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_guesser",
"//code/tools/transcompilers/unilang/compiler-frontends/bazel:bazel_rule_exporter",
"//code/tools/transcompilers/unilang/f2si_frontend_compiler:bazel_options_getter",
"//code/tools/transcompilers/unilang/compiler-frontends/cpp:cpp_exporter",
"//code/utilities/types/vectors/operators:lib",
"//code/tools/transcompilers/unilang/compiler-frontends/plant_uml_exporter:plant_uml_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/html_table:html_table_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/processing:processing_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/protobuf:protobuf_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/cpp_test:cpp_test_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/cpp_fuzz:cpp_fuzz_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/cpp_benchmark:cpp_benchmark_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/mermaid:mermaid_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/date:date_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/c:c_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_exporter",
"//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_type",
])