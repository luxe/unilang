package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")


#build main and deploy stuff
cc_binary(
    name = "crossword",
    srcs = ["crossword.cpp"],
    deps = [
        "//code/tools/crossword:crossword_maker"
    ]
)

hcp(name = "crossword_maker", deps = [
    "//code/utilities/types/vectors/creators:lib",
    "//code/utilities/printers:lib",
    "//code/utilities/types/vectors/observers:lib",
])