package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "sentence_table", deps = [
"//code/transcompilers/unilang/parser:token_value",
":sentence_table_header",
":sentence_table_row",
])

hcp(name = "sentence_table_header", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "sentence_table_row", deps = [
"//code/transcompilers/unilang/parser:token_value"
])