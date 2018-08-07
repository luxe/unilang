package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "composed_program_options", deps = [
"//code/transcompilers/unilang/user-frontend/command_line_arguments:dependency_paths",
"//code/transcompilers/unilang/user-frontend/command_line_arguments:user_chosen_export_settings",
])

hcp(name = "program_options_composer", deps = [
"//code/transcompilers/unilang/main/program_options:lib",
"//code/transcompilers/unilang/main/composed_program_options:composed_program_options",
])