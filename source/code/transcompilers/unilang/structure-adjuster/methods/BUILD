package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "methods_adjuster", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/structure-adjuster/methods/creating_methods:extra_methods_creator",
"//code/transcompilers/unilang/structure-adjuster/methods/forcers:method_chaining_enforcer",
"//code/transcompilers/unilang/structure-adjuster/methods/forcers:return_statement_enforcer",
"//code/transcompilers/unilang/structure-adjuster/methods/forcers:method_overload_adjuster",
"//code/transcompilers/unilang/structure-printer/derivers:structure_typename_deriver",
"//code/transcompilers/unilang/structure-adjuster/methods/api_and_lifetime:api_and_lifetime_creator",
])