package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

cc_binary(
    name = "gcalviz",
    srcs = ["gcalviz.cpp"],
    deps = [
        "//code/tools/gcalviz:gcalviz_runner",
        "//code/tools/gcalviz:meta_settings",
    ]
)

hcp(name = "meta_settings", deps = [
])

hcp(name = "gcalviz_runner", deps = [
    "//code/utilities/gcal:gcal_getter",
    "//code/utilities/gcal:gcal_credentials",
    "//code/tools/gcalviz/settings:default_settings_getter",
    "//code/tools/gcalviz:meta_settings",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/json/functions:lib",
    "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
    "//code/utilities/gcal/data:gcal_sorted_events",
    "//code/utilities/data_structures/unique_counter:unique_counter",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/time/date:rfc333_datetime_within_range_checker",
    "//code/utilities/types/strings/observers/comparing:lib",
])