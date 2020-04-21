package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "notation_lookup_table")
hcp(name = "special_type_notations")
hcp(name = "special_type_hungarian_notation_prefixes_and_suffixes", deps = ["special_type_notations"])
hcp(name = "hungarian_type_settings", deps = [
"notation_lookup_table",
"special_type_hungarian_notation_prefixes_and_suffixes"
])