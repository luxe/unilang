package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "root_settings", deps = [
"//code/transcompilers/unilang/options/parser:parser_settings",
"//code/transcompilers/unilang/validators/file_name:filename_validation_settings",
"//code/transcompilers/unilang/options/static_analysis:static_analysis_settings",
"//code/transcompilers/unilang/options/compiler:compile_units",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:transfer_account_settings",
"//code/utilities/diagnostic:diagnostic_settings",
"//code/transcompilers/unilang/options:remote_build_settings",
"//code/transcompilers/unilang/options:remote_program_settings",
])

hcp(name = "root_settings_getter", deps = [
"//code/transcompilers/unilang/main/program_options:lib",
"//code/transcompilers/unilang/main/root_settings:root_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_contributors_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:uber_contributors_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:hidl_options_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:bazel_options_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:cpp_options_getter",
"//code/transcompilers/unilang/compiler-frontends/plant_uml_exporter:plant_uml_options_getter",
"//code/transcompilers/unilang/compiler-frontends/html_table:html_table_options_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:file_transfer_settings_getter",
"//code/transcompilers/unilang/compiler-frontends/processing:processing_options_getter",
])