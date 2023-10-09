package(default_visibility = ["//visibility:public"])

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "letter_case",
    values = [
        "upper",
        "lower",
    ],
)

enum_cpp(
    name = "optional_letter_case",
    values = [
        "upper",
        "lower",
        "any",
    ],
)

# arranged by (N)umber (L)etter
# followed by (F)orward (B)ackward
enum_cpp(
    name = "hex_ordering",
    values = [
        "NF_LF", # most common
        "LB_NB",
        "NF_LB",
        "NB_LB",
    ],
)

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/language_basic/control_structures/looping:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/char:hex_ordering",
    ],
)
