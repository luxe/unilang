package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

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
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/json/attribute_check:json_attribute_check_settings",
    "//code/utilities/json/attribute_check:json_attribute_checker",
    "//code/tools/gcalviz/exporters:connections_exporter",
    "//code/tools/gcalviz/exporters:metrics_exporter",
    "//code/utilities/web/automate/browser:browser_settings",
    "//code/utilities/web/automate/browser:browser_creator",
    "//code/utilities/web/automate/browser:default_browser_settings_getter",
    "//code/tools/gcalviz/exporters:email_exporter",
    "//code/tools/gcalviz/exporters:email_user_info_exporter",
    "//code/tools/gcalviz/exporters:user_location_info_exporter",
])

hcp(name = "gcalviz_documentation_getter", deps = [
    "//code/transcompilers/unilang/structure/model:structure",
    "//code/transcompilers/unilang/structure/model:inlined_structures",
    "//code/utilities/converters:lib",
    "//code/utilities/json/functions:lib",
    "//code/utilities/documentation:common_documentation_getter",
])

distributable_cpp_main(
    name = "gcalviz",
    deps = [
        "//code/tools/gcalviz:gcalviz_runner",
        "//code/tools/gcalviz:meta_settings",
    ],
    description = "visualize your google calendars as a social network",
    depends = [
    ],
)