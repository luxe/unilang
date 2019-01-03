package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cpp_object(name = "when_to_show_empty_enum_comment")

cpp_object(name = "enum_utility_values_placement")

hcp(name = "enum_utility_value_option")

hcp(name = "enum_utility_values_options",
deps = [
"//code/transcompilers/unilang/options/sections/enum:enum_utility_values_placement",
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/transcompilers/unilang/options/sections/enum:enum_utility_value_option",
])

hcp(name = "enum_options",
deps = [
"//code/transcompilers/unilang/options/sections/enum:enum_utility_values_options",
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/transcompilers/unilang/options/comment/doxygen:doxygen_block_options",
"//code/transcompilers/unilang/options/comment:comment_settings",
"//code/transcompilers/unilang/options/sections/enum:when_to_show_empty_enum_comment",
])