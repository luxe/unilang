package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "root_settings",
    deps = [
        "//code/tools/transcompilers/old_unilang/f2si_frontend_compiler/pulse:transfer_account_settings",
        "//code/tools/transcompilers/old_unilang/main/root_settings:initial_diagnostics",
        "//code/tools/transcompilers/old_unilang/options:remote_build_settings",
        "//code/tools/transcompilers/old_unilang/options:remote_program_settings",
        "//code/tools/transcompilers/old_unilang/options:workspace_settings",
        "//code/tools/transcompilers/old_unilang/options/compiler:chosen_exporter",
        "//code/tools/transcompilers/old_unilang/options/compiler:compile_units",
        "//code/tools/transcompilers/old_unilang/options/parser:parser_settings",
        "//code/tools/transcompilers/old_unilang/options/static_analysis:static_analysis_settings",
        "//code/tools/transcompilers/old_unilang/validators/file_name:filename_validation_settings",
    ],
)

hcp(
    name = "root_settings_getter",
    deps = [
        "//code/tools/transcompilers/old_unilang/compiler-frontends/cpp:cpp_options_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/cpp_benchmark:cpp_benchmark_options_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/cpp_test:cpp_test_options_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/dzslides:dzslides_settings_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/hidl:hidl_options_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/html_table:html_table_options_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/java:java_settings_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/java_test:java_test_settings_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/markdown:markdown_settings_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/mermaid:mermaid_settings_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/plant_uml_exporter:plant_uml_options_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/processing:processing_options_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/protobuf:protobuf_options_getter",
        "//code/tools/transcompilers/old_unilang/compiler-frontends/slidy:slidy_settings_getter",
        "//code/tools/transcompilers/old_unilang/f2si_frontend_compiler:bazel_options_getter",
        "//code/tools/transcompilers/old_unilang/f2si_frontend_compiler:f2si_contributors_getter",
        "//code/tools/transcompilers/old_unilang/f2si_frontend_compiler:file_transfer_settings_getter",
        "//code/tools/transcompilers/old_unilang/f2si_frontend_compiler:uber_contributors_getter",
        "//code/tools/transcompilers/old_unilang/main/program_options:lib",
        "//code/tools/transcompilers/old_unilang/main/root_settings",
        "//code/tools/transcompilers/old_unilang/main/root_settings:initial_diagnostics",
        "//code/tools/transcompilers/old_unilang/tokens:get_tokens",
    ],
)

hcp(
    name = "initial_diagnostics",
    deps = [
        "//code/utilities/output/diagnostic:diagnostic_settings",
    ],
)
