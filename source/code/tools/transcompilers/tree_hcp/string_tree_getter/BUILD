package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
hcp(
    name = "hcp_maker",
    deps = [
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/tools/transcompilers/hcp-compiler/programatic/data:code",
        "//code/tools/transcompilers/hcp-compiler/programatic:code_getter",
    ],
)

cc_binary(
    name = "string_tree_getter",
    srcs = ["main.cpp"],
    deps = [
        ":hcp_maker",
        "//code/tools/transcompilers/tree_hcp/string_tree_getter/program_options:lib",
    ],
)
