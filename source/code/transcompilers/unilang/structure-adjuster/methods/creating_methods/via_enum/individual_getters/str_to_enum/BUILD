package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "str_plural_to_enum_getter", deps = [
"//code/transcompilers/unilang/structure/sections/enum/item:enum_item",
"//code/transcompilers/unilang/options/sections/enum:enum_options",
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/options/manipulation/methods/via_enum/categories:enum_utility_conversion_function_options",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "str_singular_to_enum_getter", deps = [
"//code/transcompilers/unilang/structure/sections/enum/item:enum_item",
"//code/transcompilers/unilang/options/sections/enum:enum_options",
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/options/manipulation/methods/via_enum/categories:enum_utility_conversion_function_options",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
])

hcp(name = "str_to_enum_getter", deps = [
"//code/transcompilers/unilang/structure/sections/enum/item:enum_item",
"//code/transcompilers/unilang/options/sections/enum:enum_options",
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/options/manipulation/methods/via_enum/categories:enum_utility_conversion_function_options",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/general:lib",
"//code/transcompilers/unilang/enum_printer/core:enum_value_creator",
])