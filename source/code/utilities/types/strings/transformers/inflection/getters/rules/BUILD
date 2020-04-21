package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "plural_inflection_rules_getter", deps = [
"//code/utilities/types/strings/transformers/inflection/settings/regular:plural_inflections"
])

hcp(name = "singular_inflection_rules_getter", deps = [
"//code/utilities/types/strings/transformers/inflection/settings/regular:singular_inflections"
])

hcp(name = "uninflected_words_getter")

hcp(name = "irregular_inflection_words_getter", deps = [
"//code/utilities/types/strings/transformers/inflection/settings/irregular:irregular_inflections"
])