package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "serializable_function_getter", deps = [
"//code/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/transcompilers/unilang/options/sections/data_member:data_member_options",
"//code/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/transcompilers/unilang/options/manipulation/methods/via_data_member:data_member_utility_function_options",
"//code/transcompilers/unilang/options/language-specific:c_language_version",
"//code/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters/serialization/json:serialize_json_method_getter",
"//code/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters/serialization/json:to_json_method_getter",
"//code/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters/serialization/json:json_print_method_getter",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/vectors/operators:lib",
])