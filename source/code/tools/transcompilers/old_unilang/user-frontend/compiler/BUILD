package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "compiler",
    deps = [
        "//code/tools/transcompilers/old_unilang/compiler-frontends/bazel:bazel_rule_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/c:c_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/cpp:cpp_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/cpp_benchmark:cpp_benchmark_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/cpp_fuzz:cpp_fuzz_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/cpp_test:cpp_test_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/date:date_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/hidl:hidl_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/hidl:hidl_options_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/html_table:html_table_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/java:java_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/java_test:java_test_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/markdown:markdown_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/mermaid:mermaid_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/plant_uml_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/processing:processing_exporter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/protobuf:protobuf_exporter",
        "//code/tools/transcompilers/old_unilang/dependency_graph_creator:code_graph",
        "//code/tools/transcompilers/old_unilang/f2si_frontend_compiler:bazel_options_getter",
        "//code/tools/transcompilers/old_unilang/main:program_input",
        "//code/tools/transcompilers/old_unilang/options/bazel:language_to_build_object",
        "//code/tools/transcompilers/old_unilang/user-frontend/action_graphs:actionable_code_graph",
        "//code/tools/transcompilers/old_unilang/user-frontend/action_graphs:actionable_code_graphs",
        "//code/tools/transcompilers/old_unilang/user-frontend/artifact_actions:artifact_guesser",
        "//code/utilities/formats/artifact:artifact_type",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
