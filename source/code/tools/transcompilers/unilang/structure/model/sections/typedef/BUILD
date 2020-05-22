package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "typedef_argument",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "typedef_section",
    deps = [
        "typedef_item",
    ],
)

hcp(
    name = "typedef_item",
    deps = [
        "typedef_argument",
        "typedef_result",
        "//code/tools/transcompilers/unilang/parser:token_value",
        "//code/tools/transcompilers/unilang/structure/model/sections:structure_enums",
    ],
)

hcp(
    name = "typedef_result",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)
