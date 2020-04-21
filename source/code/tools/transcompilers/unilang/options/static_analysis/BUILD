package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="static_analysis_settings",deps=[
"//code/tools/transcompilers/unilang/options/static_analysis/sections:section_analysis",
"//code/tools/transcompilers/unilang/options/static_analysis:measurement_analysis_settings",
])

hcp(name="measurement_analysis_settings",deps=[
])