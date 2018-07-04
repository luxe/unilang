package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "root_settings", deps = [
"//code/transcompilers/unilang/options/parser:parser_settings",
"//code/transcompilers/unilang/validators/file_name:filename_validation_settings",
"//code/transcompilers/unilang/options/static_analysis:static_analysis_settings",
])

hcp(name = "root_settings_getter", deps = [
"//code/transcompilers/unilang/main/program_options:lib",
"//code/transcompilers/unilang/main/root_settings:root_settings",
])