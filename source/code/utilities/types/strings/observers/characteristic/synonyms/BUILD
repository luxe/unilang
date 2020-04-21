package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name="synonym_entry",deps = [
])

hcp(name="synonym_settings",   deps = [
    "//code/utilities/types/strings/observers/characteristic/synonyms:synonym_entry",
])

hcp(name="synonyms_normalizer", deps = [
    "//code/utilities/types/strings/observers/characteristic/synonyms:synonym_settings",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/utilities/types/vectors/observers:lib",
])