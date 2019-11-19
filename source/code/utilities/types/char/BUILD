package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(name = "letter_case",
values = [
"upper"
,"lower"
])

enum_cpp(name = "optional_letter_case",
values = [
"upper"
,"lower"
,"any"
])

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/language_basic/control_structures/looping:lib",
        "//code/utilities/types/vectors/operators:lib",
    ]
)
