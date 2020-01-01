package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "root_body_element", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method/body/body-ast/comment_types:regular_body_comment",
"//code/tools/transcompilers/unilang/structure/model/sections/method/body/body-ast/comment_types:todo_body_comment",
"//code/tools/transcompilers/unilang/structure/model/sections/method/body/body-ast/comment_types:warning_body_comment",
"//code/tools/transcompilers/unilang/structure/model/sections/method/body/body-ast/statement_types:regular_statement",
"//code/tools/transcompilers/unilang/structure/model/sections/method/body/body-ast/statement_types:return_statement",
"//code/tools/transcompilers/unilang/structure/model/sections/method/body/body-ast/statement_types:uncaught_statement",
"//code/tools/transcompilers/unilang/structure/model/sections/method/body/body-ast/function_types:function_call_local",
"@boost//:variant",
])