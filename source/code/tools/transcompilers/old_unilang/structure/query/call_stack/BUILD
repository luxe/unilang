package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "direct_methods_called_by_methods_getter",
    deps = [
        "//code/utilities/comments/doxygen/settings:doxygen_parameter_direction",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method:method_item",
        "//code/utilities/code/query:argument_direction_decider",
        "//code/tools/transcompilers/old_unilang/structure/query/call_stack:direct_method_call_and_count",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
        "//code/utilities/types/variant:lib",
    ],
)

hcp(
    name = "direct_method_call_and_count",
    deps = [
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method:method_item",
    ],
)
