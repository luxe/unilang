package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp_hdrs_derive(
    name = "opendir_wrap",
    interface_deps = [
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/deps/c/dirent:lib",
        "//code/utilities/deps/c/errno:lib",
        "//code/utilities/deps/c/fcntl:lib",
        "//code/utilities/deps/c/stdio:lib",
        "//code/utilities/deps/c/stdlib:lib",
        "//code/utilities/deps/c/sys_types:lib",
    ],
)




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
