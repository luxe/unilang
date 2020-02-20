package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(name="opendir_wrap", deps = [
    "//code/utilities/types/strings/observers/other:lib",
])

cpp_main(
    name = "is_dir",
    deps = [":opendir_wrap"],
)
cpp_main(
    name = "dir_inode",
    deps = [":opendir_wrap"],
)
cpp_main(
    name = "print_readdir",
    deps = [":opendir_wrap"],
)
cpp_main(
    name = "gather_readdir",
    deps = [":opendir_wrap"],
)