package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "enum_subgroup_affiliation_function_getter", deps = [
"//code/transcompilers/unilang/structure/sections/enum/item:enum_item",
"//code/transcompilers/unilang/options/sections/enum:enum_options",
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/options/manipulation/methods/via_enum/categories:enum_utility_subgroup_affiliation_function_options",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/enum_printer/core:enum_value_creator",
"//code/utilities/types/strings/transformers/inflection/settings:inflection_settings",
"//code/utilities/types/strings/transformers/inflection:inflection_converter",
"//code/utilities/types/strings/transformers/inflection/getters:inflection_settings_getter",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods/via_enum:enum_utility_function_shared",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])