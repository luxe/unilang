package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "root_body_element", deps = [
"//code/transcompilers/unilang/structure/sections/method/body/body-ast/comment_types:regular_body_comment",
"//code/transcompilers/unilang/structure/sections/method/body/body-ast/comment_types:todo_body_comment",
"//code/transcompilers/unilang/structure/sections/method/body/body-ast/comment_types:warning_body_comment",
"//code/transcompilers/unilang/structure/sections/method/body/body-ast/statement_types:regular_statement",
"//code/transcompilers/unilang/structure/sections/method/body/body-ast/statement_types:return_statement",
"//code/transcompilers/unilang/structure/sections/method/body/body-ast/statement_types:uncaught_statement",
"@com_github_boost_variant//:variant",
])