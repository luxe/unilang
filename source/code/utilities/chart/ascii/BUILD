package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name="chart_get_settings")
hcp(name="chart_getter", deps = [
    "//code/utilities/chart/ascii:chart_get_settings",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/strings/observers/padding:lib",
    "//code/utilities/types/strings/creators:lib",
    "//code/utilities/math:math",
])