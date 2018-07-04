package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "program_input", deps = [
"//code/transcompilers/unilang/main/root_settings:root_settings",
"//code/transcompilers/unilang/main/composed_program_options:composed_program_options",
])

hcp(name = "program_input_validator", deps = [
"//code/transcompilers/unilang/main/program_options:lib",
"//code/transcompilers/unilang/main:program_input",
"//code/transcompilers/unilang/user-frontend:dependency_path_validator",
])

hcp(name = "root_exception_handler", deps = [
"//code/utilities/colors:lib",
])

hcp(name = "task_executer", deps = [
"//code/transcompilers/unilang/main/composed_program_options:composed_program_options",
"//code/transcompilers/unilang/main/root_settings:root_settings",
"//code/transcompilers/unilang/main:program_input",
"//code/transcompilers/unilang/user-frontend:user_frontend",
])

cc_binary(name = "unilang-transcompiler",
	srcs = ["main.cpp"],
	deps = [
"//code/transcompilers/unilang/main/program_options:lib",
"//code/transcompilers/unilang/main:root_exception_handler",
"//code/transcompilers/unilang/main/composed_program_options:composed_program_options",
"//code/transcompilers/unilang/main/composed_program_options:program_options_composer",
"//code/transcompilers/unilang/main/root_settings:root_settings",
"//code/transcompilers/unilang/main/root_settings:root_settings_getter",
"//code/transcompilers/unilang/main:task_executer",
"//code/transcompilers/unilang/main:program_input",
"//code/transcompilers/unilang/main:program_input_validator",
])