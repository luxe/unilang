package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(name = "class_divider_type",
values = 
["dotted",
"double",
"solid"
])

hcp(name = "plant_uml_settings", deps = [
"//code/utilities/types/strings/transformers/casing:case_format_style",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
":skin_param_settings",
":show_hide_settings",
":description_section_settings"
])

hcp(name = "skin_param_settings", deps = [
])

hcp(name = "show_hide_settings", deps = [
])

hcp(name = "description_section_settings", deps = [
":class_divider_type",
])
