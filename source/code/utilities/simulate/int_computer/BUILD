package(default_visibility = ["//visibility:public"])
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

enum_cpp(
    name = "operation_type",
    values = [
        "nop",
        "acc",
        "jmp",
    ],
)

hcp(name = "instruction", deps = [
    "//code/utilities/simulate/int_computer:operation_type",
])

hcp(name = "instructions_getter", deps = [
    "//code/utilities/types/strings/observers/splitting:lib",
    "//code/utilities/simulate/int_computer:instruction",
    "//code/utilities/types/strings/observers/converting:lib",
])

hcp(name = "int_computer", deps = [
    "//code/utilities/simulate/int_computer:instruction",
])

hcp(name = "int_computer_runner", deps = [
    "//code/utilities/data_structures:halting_problem_result",
    "//code/utilities/simulate/int_computer:int_computer",
])