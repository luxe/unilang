package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "methods_adjuster",
    deps = [
        "//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
        "//code/tools/transcompilers/unilang/structure/adjust:comment_adjuster",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/api_and_lifetime:api_and_lifetime_creator",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/creating_methods:extra_methods_creator",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/forcers:function_unit_test_name_defaulter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/forcers:immutable_value_to_immutable_ref_adjuster",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/forcers:instantiate_and_return_injector_for_return_type",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/forcers:method_chaining_enforcer",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/forcers:method_overload_adjuster",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/forcers:methods_sorter",
        "//code/tools/transcompilers/unilang/structure/adjust/methods/forcers:return_statement_enforcer",
        "//code/tools/transcompilers/unilang/structure/model:structure",
        "//code/tools/transcompilers/unilang/structure/print/derivers:structure_typename_deriver",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
