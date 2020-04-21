package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "method_item", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method/arguments/argument:template_argument",
"//code/tools/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_argument",
"//code/tools/transcompilers/unilang/structure/model/sections/method/arguments/argument:function_result",
"//code/tools/transcompilers/unilang/structure/model/sections:structure_enums",
"//code/tools/transcompilers/unilang/parser:token_value",
"//code/tools/transcompilers/unilang/parser/body_parser:body_token_value",
"//code/tools/transcompilers/unilang/structure/model/sections/method/contracts:method_contracts_section",
"//code/tools/transcompilers/unilang/structure/model/sections/method/properties:method_overload_specifiers",
"//code/tools/transcompilers/unilang/structure/model/sections/method/properties:method_inheritence_specifiers",
"//code/tools/transcompilers/unilang/structure/model/sections/method/properties:method_event_characteristic",
"//code/tools/transcompilers/unilang/structure/model/unit_tests:unit_tests",
"//code/tools/transcompilers/unilang/structure/model/benchmarks:benchmarks",
"//code/tools/transcompilers/unilang/structure/model/sections/method/stamps:method_stamp",
"//code/tools/transcompilers/unilang/structure/model/sections/method/names:method_names_section",
"//code/tools/transcompilers/unilang/structure/model/sections/method/body:function_body",
])
hcp(name = "method_section", deps = [
"method_item",
])