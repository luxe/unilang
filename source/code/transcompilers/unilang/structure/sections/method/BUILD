package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "method_item", deps = [
"//code/transcompilers/unilang/structure/sections/method/arguments/argument:template_argument",
"//code/transcompilers/unilang/structure/sections/method/arguments/argument:function_argument",
"//code/transcompilers/unilang/structure/sections/method/arguments/argument:function_result",
"//code/transcompilers/unilang/structure/sections:structure_enums",
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/parser/body_parser:body_token_value",
"//code/transcompilers/unilang/structure/sections/method/contracts:method_contracts_section",
"//code/transcompilers/unilang/structure/sections/method/properties:method_overload_specifiers",
"//code/transcompilers/unilang/structure/sections/method/properties:method_inheritence_specifiers",
"//code/transcompilers/unilang/structure/sections/method/properties:method_event_characteristic",
"//code/transcompilers/unilang/structure/unit_tests:unit_tests",
"//code/transcompilers/unilang/structure/sections/method/stamps:method_stamp",
"//code/transcompilers/unilang/structure/sections/method/names:method_names_section",
"//code/transcompilers/unilang/structure/sections/method/body:function_body",
])
hcp(name = "method_section", deps = [
"method_item",
])