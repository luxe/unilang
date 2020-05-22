package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "serializable_function_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_language_version",
        "//code/tools/transcompilers/unilang/options/manipulation/methods/via_data_member:data_member_utility_function_options",
        "//code/tools/transcompilers/unilang/options/sections/data_member:data_member_options",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters/serialization/json:json_print_method_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters/serialization/json:serialize_json_method_getter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members/individual_getters/serialization/json:to_json_method_getter",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
