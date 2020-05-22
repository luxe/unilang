package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "sentence_table",
    deps = [
        ":sentence_table_header",
        ":sentence_table_row",
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "sentence_table_header",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "sentence_table_row",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)
