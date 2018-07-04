package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "hungarian_left_prefix_decider", deps = [
"//code/transcompilers/unilang/options/hungarian/characteristic:hungarian_characteristic_settings",
"//code/utilities/exits:lib"
])
hcp("hungarian_type_prefix_decider", deps = [
"//code/transcompilers/unilang/options/hungarian/type:hungarian_type_settings",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/trimming:lib"
])