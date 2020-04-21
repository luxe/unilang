package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")


hcp(name = "bdf_settings_to_format", deps = [
   "//code/utilities/fonts/bdf/settings:bdf_settings",
   "//code/utilities/fonts/bdf/exporter:bdf_character_name_deriver"
])

hcp(name = "bdf_character_name_deriver", deps = [
   "//code/utilities/fonts/bdf/settings:bdf_settings",
   "//code/utilities/types/strings/transformers/casing:lib",
   "//code/utilities/types/strings/transformers/removing:lib",
])