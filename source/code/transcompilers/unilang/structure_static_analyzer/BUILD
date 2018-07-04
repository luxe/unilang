package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "structure_static_analyzer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/static_analysis:static_analysis_settings",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/converters:lib",
])