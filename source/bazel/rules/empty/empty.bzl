load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/data:data_getter.bzl", "data_getter")

def empty_file(target_name, file_name):

    #create file
    native.genrule(
        name = target_name,
        srcs = [],
        outs = [file_name],
        cmd = "echo -n > \"$@\"",
    )
