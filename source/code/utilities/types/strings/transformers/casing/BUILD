package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cpp_object(
    name = "lib",
    deps = ["//code/utilities/types/strings/transformers/squeeze:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/types/strings/transformers/search_replace:lib"]
)

cpp_object(
    name = "case_format_style",
)

hcp(
name = "case_modifier",
deps = ["lib","case_format_style"]
)