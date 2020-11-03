package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "method_item",
    deps = [
        "//code/tools/transcompilers/old_unilang/parser:token_value",
        "//code/tools/transcompilers/old_unilang/parser/body_parser:body_token_value",
        "//code/tools/transcompilers/old_unilang/structure/model/benchmarks",
        "//code/tools/transcompilers/old_unilang/structure/model/sections:structure_enums",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method/arguments/argument:function_argument",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method/arguments/argument:function_result",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method/arguments/argument:template_argument",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method/body:function_body",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method/contracts:method_contracts_section",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method/names:method_names_section",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method/properties:method_event_characteristic",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method/properties:method_inheritence_specifiers",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method/properties:method_overload_specifiers",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method/stamps:method_stamp",
        "//code/tools/transcompilers/old_unilang/structure/model/unit_tests",
    ],
)

hcp(
    name = "method_section",
    deps = [
        "method_item",
    ],
)
