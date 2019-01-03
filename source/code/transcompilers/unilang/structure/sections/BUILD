package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object("structure_enums")
cpp_object("existence_reason")

hcp(name = "library_dependency", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "module_dependency", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "type_specialization", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/sections/data_member:scope_specifier"
])