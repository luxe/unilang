package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object("structure_enums")

cpp_object("existence_reason")

hcp(
    name = "library_dependency",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "module_dependency",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "type_specialization",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:scope_specifier",
    ],
)
