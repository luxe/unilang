package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")


hcp(name = "inflection_settings_getter", deps = [
"//code/utilities/types/strings/transformers/inflection/settings:inflection_settings",
"//code/utilities/types/strings/transformers/inflection/getters/rules:singular_inflection_rules_getter",
"//code/utilities/types/strings/transformers/inflection/getters/rules:plural_inflection_rules_getter",
"//code/utilities/types/strings/transformers/inflection/getters/rules:irregular_inflection_words_getter",
"//code/utilities/types/strings/transformers/inflection/getters/rules:uninflected_words_getter",
])