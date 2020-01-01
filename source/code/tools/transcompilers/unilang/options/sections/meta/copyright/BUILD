package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(
	name = "meta_copyright_print_method"
)
hcp(
	name = "meta_copyright_tag_options",
	deps = ["meta_copyright_print_method"]
)