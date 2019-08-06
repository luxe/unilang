package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name="gexf_formatter", deps = [
    "//code/tools/gcalviz/exporters/data:node_edge_data",
    "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
    "//code/utilities/time/date:rfc333_datetime_within_range_checker",
    "//code/utilities/gcal/data:gcal_sorted_events",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/json/functions:lib",
    "//code/utilities/data_structures/unique_counter:unique_counter",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/comparing:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/tools/gcalviz/exporters/data:edge_data",
    "//code/tools/gcalviz/exporters/formatters:gexf_attribute",
])

hcp(name="graphml_formatter", deps = [
    "//code/tools/gcalviz/exporters/data:node_edge_data",
    "//code/utilities/time/date:rfc333_datetime_to_epoch_converter",
    "//code/utilities/time/date:rfc333_datetime_within_range_checker",
    "//code/utilities/gcal/data:gcal_sorted_events",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/json/functions:lib",
    "//code/utilities/data_structures/unique_counter:unique_counter",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/comparing:lib",
    "//code/utilities/types/strings/observers/other:lib",
])

hcp(name="gexf_attribute", deps = [
    "//code/utilities/json/extraction:json_extraction_settings",
])