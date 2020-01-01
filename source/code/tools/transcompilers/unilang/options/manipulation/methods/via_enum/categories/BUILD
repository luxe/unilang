package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "enum_utility_subgroup_affiliation_function_options")

hcp(name = "function_build_settings", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections:structure_enums",
])

hcp(name = "enum_utility_conversion_function_options", deps = [
"function_build_settings"
])

hcp(name = "enum_utility_iteration_function_options", deps = [
"function_build_settings"
])

hcp(name = "enum_utility_special_value_function_options", deps = [
"function_build_settings"
])