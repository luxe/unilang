package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "inflection_settings", deps = [
"//code/utilities/types/strings/transformers/inflection/settings/regular:singular_inflections",
"//code/utilities/types/strings/transformers/inflection/settings/regular:plural_inflections",
"//code/utilities/types/strings/transformers/inflection/settings/irregular:irregular_inflections",
])