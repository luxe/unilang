package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/time/calendar/months:lib",
        "//code/utilities/time/calendar/tm_wrappers:lib",
    ],
)

hcp(
    name = "rfc333_datetime_to_epoch_converter",
    deps = [
        "@date",
    ],
)

hcp(
    name = "rfc333_datetime_range",
    deps = [
    ],
)

hcp(
    name = "rfc333_datetime_within_range_checker",
    deps = [
        ":rfc333_datetime_range",
        ":rfc333_datetime_to_epoch_converter",
    ],
)
