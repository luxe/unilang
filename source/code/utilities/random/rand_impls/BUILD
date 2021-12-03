package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:gtest.bzl", "gtest")
load("@rules_fuzzing//fuzzing:cc_defs.bzl", "cc_fuzz_test")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "random_number_generator",
    values = [

        #example definition in the C/C++ standard
        "posix_1_2001_example",
        "glib_rand",  #whatever is in the C library

        #used in web browsers
        "xorshift128plus",

        #arc4
        "arc4_rand32",
        "arc4_rand64",

        #chaha
        "chacha4",
        "chacha5",
        "chacha6",
        "chacha8",
        "chacha12",
        "chacha20",

        #pretty common
        "mt19937_32",
        "mt19937_64",
        "mt19937_PHP",  #PHP had a buggy impl
        "mwc1616",
        "minstd",

        #actual entropy
        "urandom",

        #actual entropy from a recorded past
        "nonce",

        #the worst PRNG ever
        "incrementing_numbers",
    ],
)

hcp_hdrs_derive(
    name = "rng_state",
    interface_deps = [
    ],
)

cc_library(
    name = "posix_1_2001_example",
    srcs = ["posix_1_2001_example.cpp"],
    hdrs = ["posix_1_2001_example.hpp"],
    deps = [
    ],
)

cc_library(
    name = "mwc1616",
    srcs = ["mwc1616.cpp"],
    hdrs = ["mwc1616.hpp"],
    deps = [
    ],
)

cc_library(
    name = "xorshift128plus",
    srcs = ["xorshift128plus.cpp"],
    hdrs = ["xorshift128plus.hpp"],
    deps = [
    ],
)

cc_library(
    name = "arc4",
    srcs = ["arc4.cpp"],
    hdrs = ["arc4.hpp"],
    deps = [
    ],
)

cc_library(
    name = "chacha",
    srcs = ["chacha.cpp"],
    hdrs = ["chacha.hpp"],
    deps = [
    ],
)
