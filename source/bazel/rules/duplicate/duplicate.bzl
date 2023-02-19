load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/data:data_getter.bzl", "data_getter")

def sh_test_duplicate(name,srcs,amount):
    
    for index in range(amount):
        native.sh_test(
            name = name + str(index),
            srcs = srcs,
        )
