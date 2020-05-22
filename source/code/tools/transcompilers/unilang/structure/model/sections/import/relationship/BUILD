package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "type_relationships",
    deps = [
    ],
)

hcp(
    name = "import_relationship",
    deps = [
        "type_relationships",
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)
