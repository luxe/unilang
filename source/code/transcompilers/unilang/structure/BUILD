package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cpp_object("forward_decls")

hcp(name = "inlined_structures", deps = [
"forward_decls",
"structure"
])

hcp(name = "structure", deps = [
"//code/transcompilers/unilang/structure:forward_decls",
"//code/transcompilers/unilang/structure/sections/meta:meta_section",
"//code/transcompilers/unilang/structure/sections/types:type_section",
"//code/transcompilers/unilang/structure/sections/import:import_section",
"//code/transcompilers/unilang/structure/sections/library:library_section",
"//code/transcompilers/unilang/structure/sections/compiler_options:compile_options",
"//code/transcompilers/unilang/structure/sections/linker_options:link_options",
"//code/transcompilers/unilang/structure/sections/macro:macro_section",
"//code/transcompilers/unilang/structure/sections/namespace:namespace_section",
"//code/transcompilers/unilang/structure/sections/templates:template_section",
"//code/transcompilers/unilang/structure/sections/inheritance:inheritance_section",
"//code/transcompilers/unilang/structure/sections/method:method_section",
"//code/transcompilers/unilang/structure/sections/typedef:typedef_section",
"//code/transcompilers/unilang/structure/sections/forward_declare:forward_declare_section",
"//code/transcompilers/unilang/structure/sections/data_member:data_member_section",
"//code/transcompilers/unilang/structure/sections/enum:enum_section",
"//code/transcompilers/unilang/structure/unit_tests:unit_tests",
"@com_github_boost_variant//:variant",
])