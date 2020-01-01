package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
	name = "test_enum",
	values = ["foo","bar","baz"]
)

cc_binary(
    name = "enum_program",
    srcs = ["test.cc"],
    deps = ["//code/transcompilers/enum_cpp/example:test_enum"],
)