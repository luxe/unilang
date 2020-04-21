package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "enums_adjuster", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/tools/transcompilers/unilang/structure/adjust/enums:enum_standard_incrementer",
"//code/tools/transcompilers/unilang/structure/adjust/enums:enum_value_inserter",
"//code/tools/transcompilers/unilang/structure/adjust:comment_adjuster",
])

hcp(name = "enum_standard_incrementer", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
"//code/utilities/colors:lib"
])

hcp(name = "enum_value_inserter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
])