package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "type_adjuster",
    deps = [
        "//code/tools/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
        "//code/tools/transcompilers/unilang/structure/adjust:comment_adjuster",
        "//code/tools/transcompilers/unilang/structure/model:structure",
    ],
)
