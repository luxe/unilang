package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object("forward_decls")

hcp(
    name = "inlined_structures",
    deps = [
        "forward_decls",
        "structure",
    ],
)

hcp(
    name = "structure",
    deps = [
        "//code/tools/transcompilers/unilang/structure/model:forward_decls",
        "//code/tools/transcompilers/unilang/structure/model/benchmarks",
        "//code/tools/transcompilers/unilang/structure/model/sections/compiler_options:compile_options",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/enum:enum_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/forward_declare:forward_declare_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/import:import_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/inheritance:inheritance_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/library:library_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/linker_options:link_options",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature:literature_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/macro:macro_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/meta:meta_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/namespace:namespace_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/templates:template_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/typedef:typedef_section",
        "//code/tools/transcompilers/unilang/structure/model/sections/types:type_section",
        "//code/tools/transcompilers/unilang/structure/model/unit_tests",
        "@boost//:container",
        "@boost//:variant",
    ],
)
