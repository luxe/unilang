package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "enums_adjuster", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/structure-adjuster/enums:enum_standard_incrementer",
"//code/transcompilers/unilang/structure-adjuster/enums:enum_value_inserter",
"//code/transcompilers/unilang/structure-adjuster:comment_adjuster",
])

hcp(name = "enum_standard_incrementer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/sections/enum/item:enum_item",
"//code/utilities/colors:lib"
])

hcp(name = "enum_value_inserter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure/sections/enum/item:enum_item",
])