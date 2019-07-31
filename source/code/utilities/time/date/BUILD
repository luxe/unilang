package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
"//code/utilities/time/calendar/tm_wrappers:lib",
"//code/utilities/time/calendar/months:lib"
])

hcp(name="rfc333_datetime_to_epoch_converter")