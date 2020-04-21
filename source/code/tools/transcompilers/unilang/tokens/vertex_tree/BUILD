package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/unilang:generate_unilang_token_files.bzl", "generate_unilang_token_files")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "as_vertex_graph",
    deps = ["//code/utilities/data_structures/unique_str_vertex_graph:lib"]
)

cc_binary(
    name = "print_token_tree",
    srcs = ["print_token_tree.cpp"],
    deps = ["as_vertex_graph"]
)