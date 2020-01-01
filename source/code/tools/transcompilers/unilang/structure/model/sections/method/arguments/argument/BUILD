package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "function_argument", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/model/sections/method/arguments:usage_requirement",
"//code/transcompilers/unilang/structure/model/sections:type_specialization",
"//code/transcompilers/unilang/structure/model/sections/data_member:scope_specifier",
"//code/transcompilers/unilang/structure/model/sections:module_dependency",
"//code/transcompilers/unilang/structure/model/sections:library_dependency",
])

hcp(name = "function_result", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/model/sections/method/arguments:usage_requirement",
"//code/transcompilers/unilang/structure/model/sections:type_specialization",
"//code/transcompilers/unilang/structure/model/sections/data_member:scope_specifier",
"//code/transcompilers/unilang/structure/model/sections:module_dependency",
"//code/transcompilers/unilang/structure/model/sections:library_dependency",
])

hcp(name = "template_argument", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/model/sections/method/arguments:usage_requirement",
"//code/transcompilers/unilang/structure/model/sections/data_member:scope_specifier",
"//code/transcompilers/unilang/structure/model/sections:module_dependency",
"//code/transcompilers/unilang/structure/model/sections:library_dependency",
])