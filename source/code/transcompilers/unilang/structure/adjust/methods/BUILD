package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "methods_adjuster", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/structure/adjust/methods/creating_methods:extra_methods_creator",
"//code/transcompilers/unilang/structure/adjust/methods/forcers:method_chaining_enforcer",
"//code/transcompilers/unilang/structure/adjust/methods/forcers:return_statement_enforcer",
"//code/transcompilers/unilang/structure/adjust/methods/forcers:method_overload_adjuster",
"//code/transcompilers/unilang/structure-printer/derivers:structure_typename_deriver",
"//code/transcompilers/unilang/structure/adjust/methods/api_and_lifetime:api_and_lifetime_creator",
"//code/transcompilers/unilang/structure/adjust/methods/forcers:immutable_value_to_immutable_ref_adjuster",
"//code/transcompilers/unilang/structure/adjust/methods/forcers:instantiate_and_return_injector_for_return_type",
"//code/transcompilers/unilang/structure/adjust/methods/forcers:function_unit_test_name_defaulter",
"//code/transcompilers/unilang/structure/adjust:comment_adjuster",
])