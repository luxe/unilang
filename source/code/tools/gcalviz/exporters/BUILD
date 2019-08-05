package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name="connections_exporter", deps = [
    "//code/utilities/gcal/data:gcal_sorted_events",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/json/functions:lib",
    "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
    "//code/utilities/time/date:rfc333_datetime_within_range_checker",
    "//code/utilities/data_structures/unique_counter:unique_counter",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/comparing:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/tools/gcalviz/exporters/data:node_edge_data",
    "//code/tools/gcalviz/exporters/formatters:gexf_formatter",
    "//code/tools/gcalviz/exporters/formatters:graphml_formatter",
    "//code/tools/gcalviz/exporters/data:edge_data",
    "//code/utilities/json/attribute_check:json_attribute_check_settings",
    "//code/utilities/json/attribute_check:json_attribute_checker",
])

hcp(name="metrics_exporter", deps = [
    "//code/utilities/gcal/data:gcal_sorted_events",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/json/functions:lib",
    "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
    "//code/utilities/time/date:rfc333_datetime_within_range_checker",
    "//code/utilities/data_structures/unique_counter:unique_counter",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/comparing:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/gcal/data:gcal_rooms",
])

hcp(name="email_exporter", deps = [
    "//code/utilities/gcal/data:gcal_sorted_events",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/json/functions:lib",
    "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
    "//code/utilities/time/date:rfc333_datetime_within_range_checker",
    "//code/utilities/data_structures/unique_counter:unique_counter",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/comparing:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/gcal/data:gcal_rooms",
    "//code/utilities/json/attribute_check:json_attribute_check_settings",
    "//code/utilities/json/attribute_check:json_attribute_checker",
])

hcp(name="email_user_info_exporter", deps = [
    "//code/utilities/gcal/data:gcal_sorted_events",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/json/functions:lib",
    "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
    "//code/utilities/time/date:rfc333_datetime_within_range_checker",
    "//code/utilities/data_structures/unique_counter:unique_counter",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/comparing:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/gcal/data:gcal_rooms",
    "//code/utilities/json/attribute_check:json_attribute_check_settings",
    "//code/utilities/json/attribute_check:json_attribute_checker",
    "@pybind11//:pybind11",
    "//code/utilities/signals:lib",
    "//code/utilities/web/automate/navigation:browser_navigator",
    "//code/utilities/web/automate/browser:browser_settings",
    "//code/utilities/web/automate/browser:browser_creator",
    "//code/utilities/web/automate/browser:default_browser_settings_getter",
])