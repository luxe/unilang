package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "extra_methods_creator", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_enum:enum_utility_function_getter",
"//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_data_members:data_member_utility_function_getter",
"//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods/via_other_methods:method_utility_function_getter",
"//code/tools/transcompilers/unilang/structure/adjust/methods/forcers:method_chaining_enforcer",
"//code/tools/transcompilers/unilang/structure/adjust/methods/forcers:return_statement_enforcer",
"//code/tools/transcompilers/unilang/structure/adjust/methods/forcers:method_overload_adjuster",
"//code/tools/transcompilers/unilang/structure/print/derivers:structure_typename_deriver",
])