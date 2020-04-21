package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "method_contract_settings",deps = [
"//code/tools/transcompilers/unilang/options/sections/meta/other:meta_tag_existence_option"
])

hcp(name = "method_subgroup_settings")

hcp(name = "method_options", deps = [
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/tools/transcompilers/unilang/options/comment/doxygen:doxygen_block_options",
"//code/tools/transcompilers/unilang/options/sections/method/parameters:method_parameter_settings",
"//code/tools/transcompilers/unilang/options/comment:comment_settings",
"//code/tools/transcompilers/unilang/options/sections/method/attributes:all_method_attribute_settings",
"//code/tools/transcompilers/unilang/options/sections/method/sorting:method_sorting_settings",
"method_contract_settings",
"method_subgroup_settings",
"outside_body_comment_settings",
"method_divider_settings",
"//code/tools/transcompilers/unilang/options/sections/method:method_test_case_settings",
"//code/tools/transcompilers/unilang/options/sections/method:method_benchmark_case_settings",
])

hcp(name = "outside_body_comment_settings", deps = [
"//code/tools/transcompilers/unilang/options/comment:comment_settings"
])

hcp(name = "divider_settings")
hcp(name = "method_divider_settings", deps = [
"//code/tools/transcompilers/unilang/options/sections/method:divider_settings",
])

hcp(name = "method_test_case_settings", deps = [
"//code/tools/transcompilers/unilang/options/sections/method:divider_settings",
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/tools/transcompilers/unilang/options/sections/method:method_test_case_speed_settings",
])

hcp(name = "method_benchmark_case_settings", deps = [
"//code/tools/transcompilers/unilang/options/sections/method:divider_settings",
"//code/utilities/types/strings/transformers/casing:case_format_style"
])

hcp(name = "method_test_case_speed_settings")