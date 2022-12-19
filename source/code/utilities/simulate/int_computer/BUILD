package(default_visibility = ["//visibility:public"])

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

enum_cpp(
    name = "operation_type",
    values = [
        "nop",
        "acc", #short for accumulate
        "jmp",
    ],
)


hcp_hdrs_derive(
    name = "instruction",
    interface_deps = [
        "//code/utilities/simulate/int_computer:operation_type",
    ],
)


hcp_hdrs_derive(
    name = "instructions_getter_settings",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "instructions_getter",
    interface_deps = [
        "//code/utilities/simulate/int_computer:instruction",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/simulate/int_computer:instructions_getter_settings",
    ],
)


hcp_hdrs_derive(
    name = "int_computer",
    interface_deps = [
        "//code/utilities/simulate/int_computer:instruction",
        "//code/utilities/deps/stl/unordered_set:lib",
    ],
)


hcp_hdrs_derive(
    name = "int_computer_runner",
    interface_deps = [
        "//code/utilities/data_structures:halting_problem_result",
        "//code/utilities/simulate/int_computer",
    ],
)
