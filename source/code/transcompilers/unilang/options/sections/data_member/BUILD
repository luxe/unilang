package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "data_member_casing_settings",
deps = ["//code/utilities/types/strings/transformers/casing:case_format_style"]
)

hcp(name = "data_member_options",
deps = [
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/transcompilers/unilang/options/comment/doxygen:doxygen_block_options",
"//code/transcompilers/unilang/options/comment:comment_settings",
"//code/transcompilers/unilang/options/sections:notation_settings",
"//code/transcompilers/unilang/options/sections/data_member:data_member_casing_settings",
])