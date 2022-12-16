package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = ["//code/utilities/types/char:lib"],
)

hcp_hdrs_derive(
    name = "english_number_to_integral_converter",
    interface_deps = [
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp_hdrs_derive(
    name = "is_english_number_checker",
    interface_deps = [
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp_hdrs_derive(
    name = "is_month_word_checker",
    interface_deps = [
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp_hdrs_derive(
    name = "is_weekday_checker",
    interface_deps = [
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp_hdrs_derive(
    name = "is_cpp_keyword_checker",
    interface_deps = [
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp_hdrs_derive(
    name = "spirit_numeric_checker",
    interface_deps = [
        "//code/utilities/deps/external/boost_foreach:lib",
        "//code/utilities/deps/external/boost_range:lib",
        "//code/utilities/deps/external/boost_spirit:lib",
    ],
)
