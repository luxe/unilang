package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "comparison_function_build_settings",deps = [
"//code/transcompilers/unilang/options/manipulation/methods/via_enum/categories:function_build_settings"
])

hcp(name = "data_member_utility_function_options",deps = [
"//code/transcompilers/unilang/options/manipulation/methods/via_enum/categories:function_build_settings",
"comparison_function_build_settings"
])