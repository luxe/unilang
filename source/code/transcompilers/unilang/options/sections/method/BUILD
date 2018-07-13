package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "method_contract_settings",deps = [
"//code/transcompilers/unilang/options/sections/meta/other:meta_tag_existence_option"
])

hcp(name = "method_subgroup_settings")

hcp(name = "method_options", deps = [
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/transcompilers/unilang/options/comment/doxygen:doxygen_block_options",
"//code/transcompilers/unilang/options/sections/method/parameters:method_parameter_settings",
"//code/transcompilers/unilang/options/comment:comment_settings",
"//code/transcompilers/unilang/options/sections/method/attributes:all_method_attribute_settings",
"//code/transcompilers/unilang/options/sections/method/sorting:method_sorting_settings",
"method_contract_settings",
"method_subgroup_settings",
"outside_body_comment_settings",
"method_divider_settings",
"//code/transcompilers/unilang/options/sections/method:method_test_case_settings",
])

hcp(name = "outside_body_comment_settings", deps = [
"//code/transcompilers/unilang/options/comment:comment_settings"
])

hcp(name = "divider_settings")
hcp(name = "method_divider_settings", deps = [
"//code/transcompilers/unilang/options/sections/method:divider_settings",
])

hcp(name = "method_test_case_settings", deps = [
"//code/transcompilers/unilang/options/sections/method:divider_settings",
"//code/utilities/types/strings/transformers/casing:case_format_style",
])