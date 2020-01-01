package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "type_property_word")

hcp(name = "weighted_type_property_word",deps=[
"//code/tools/transcompilers/unilang/options/self_describe_type:type_property_word"
])

hcp(name = "type_properties_to_identifier_words", deps = [
"//code/utilities/types:tri_string"
])

hcp(name = "modify_identifier_with_extra_type_info", deps = [
"identifier_with_type_info",
"extra_type_suffix_settings",
"//code/utilities/types:tri_bool",
"//code/utilities/types:tri_string",
"weighted_type_property_word",
"//code/utilities/types/strings/transformers/inflection/getters:inflection_settings_getter",
"//code/utilities/types/strings/transformers/inflection:inflection_converter",
])

hcp(name = "inferred_type_properties", deps = [
"//code/utilities/types:tri_bool"
])

hcp(name = "identifier_with_type_info", deps = [
"//code/utilities/types:tri_bool"
])

hcp(name = "extra_type_suffix_settings", deps = [
"type_properties_to_identifier_words"
])