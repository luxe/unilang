package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "counted_object",
    deps = [
    ],
)

hcp(
    name = "counted_object_parser",
    deps = [
        "//code/utilities/linguistics/counted_object",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/inflection:inflection_converter",
        "//code/utilities/types/strings/transformers/inflection/getters:inflection_settings_getter",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)
