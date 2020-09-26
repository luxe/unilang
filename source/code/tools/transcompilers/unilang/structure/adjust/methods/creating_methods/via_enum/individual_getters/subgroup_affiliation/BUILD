package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "enum_subgroup_affiliation_function_getter",
    deps = [
        "//code/tools/transcompilers/unilang/enum_printer/core:enum_value_creator",
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_enum/categories:enum_utility_subgroup_affiliation_function_options",
        "//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum:enum_utility_function_shared",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/inflection:inflection_converter",
        "//code/utilities/types/strings/transformers/inflection/getters:inflection_settings_getter",
        "//code/utilities/types/strings/transformers/inflection/settings:inflection_settings",
    ],
)
