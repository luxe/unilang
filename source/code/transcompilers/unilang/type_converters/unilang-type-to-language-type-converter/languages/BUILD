package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

cpp_object(name = "source_language")
hcp(name = "equivalent_language_types", deps = [
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages/language_type:language_type",
"//code/utilities/types:tri_bool",
"//code/transcompilers/unilang/options/self_describe_type:inferred_type_properties",
])