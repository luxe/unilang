package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/time/calendar/months:lib",
        "//code/utilities/time/calendar/tm_wrappers:lib",
    ],
)

hcp_hdrs_derive(
    name = "rfc333_datetime_to_epoch_converter",
    interface_deps = [
        "//code/utilities/deps/external/date:lib",
    ],
)

hcp_hdrs_derive(
    name = "rfc333_datetime_range",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "rfc333_datetime_within_range_checker",
    interface_deps = [
        "//code/utilities/time/date:rfc333_datetime_range",
        "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
    ],
)
