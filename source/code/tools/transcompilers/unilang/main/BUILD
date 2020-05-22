package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "program_input",
    deps = [
        "//code/tools/transcompilers/unilang/main/composed_program_options",
        "//code/tools/transcompilers/unilang/main/root_settings",
    ],
)

hcp(
    name = "program_input_validator",
    deps = [
        "//code/tools/transcompilers/unilang/main:program_input",
        "//code/tools/transcompilers/unilang/main/program_options:lib",
        "//code/tools/transcompilers/unilang/user-frontend:dependency_path_validator",
    ],
)

hcp(
    name = "root_exception_handler",
    deps = [
        "//code/utilities/colors:lib",
        "@boost//:exception",
        "@boost//:smart_ptr",
        "@boost//:throw_exception",
    ],
)

hcp(
    name = "task_executer",
    deps = [
        "//code/tools/transcompilers/unilang/main:program_input",
        "//code/tools/transcompilers/unilang/main/composed_program_options",
        "//code/tools/transcompilers/unilang/main/root_settings",
        "//code/tools/transcompilers/unilang/user-frontend:user_frontend",
    ],
)

cc_binary(
    name = "unilang-transcompiler",
    srcs = ["main.cpp"],
    deps = [
        "//code/tools/transcompilers/unilang/main:program_input",
        "//code/tools/transcompilers/unilang/main:program_input_validator",
        "//code/tools/transcompilers/unilang/main:root_exception_handler",
        "//code/tools/transcompilers/unilang/main:task_executer",
        "//code/tools/transcompilers/unilang/main/composed_program_options",
        "//code/tools/transcompilers/unilang/main/composed_program_options:program_options_composer",
        "//code/tools/transcompilers/unilang/main/program_options:lib",
        "//code/tools/transcompilers/unilang/main/root_settings",
        "//code/tools/transcompilers/unilang/main/root_settings:root_settings_getter",
    ],
)
