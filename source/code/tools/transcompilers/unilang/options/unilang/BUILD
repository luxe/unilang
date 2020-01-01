package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "unilang_section_settings")

hcp(name = "unilang_general_settings")

hcp(name = "unilang_export_settings",deps = [
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"unilang_section_settings",
"unilang_general_settings"
])