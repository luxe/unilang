load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "repo_transferer")

cc_binary(
    name = "transfer-self-repo",
    srcs = ["main.cc"],
    deps = ["//code/self-transfer:repo_transferer"],
    linkopts = [],
)