package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "citation",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature/citation:citation_attribute",
    ],
)

hcp(
    name = "citation_attribute",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)
