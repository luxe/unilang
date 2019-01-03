package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "section_analysis",
deps = [
"//code/transcompilers/unilang/options/static_analysis/sections/meta:meta_analysis",
"//code/transcompilers/unilang/options/static_analysis/sections/import:import_analysis",
"//code/transcompilers/unilang/options/static_analysis/sections/namespace:namespace_analysis",
"//code/transcompilers/unilang/options/static_analysis/sections/inheritance:inheritance_analysis",
"//code/transcompilers/unilang/options/static_analysis/sections/macro:macro_analysis",
"//code/transcompilers/unilang/options/static_analysis/sections/enum:enum_analysis",
"//code/transcompilers/unilang/options/static_analysis/sections/typedef:typedef_analysis",
"//code/transcompilers/unilang/options/static_analysis/sections/method:method_analysis",
"//code/transcompilers/unilang/options/static_analysis/sections/data_member:data_member_analysis"
])