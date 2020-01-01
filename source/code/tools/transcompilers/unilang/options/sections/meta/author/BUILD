package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(
	name = "author_order_method"
)

cpp_object(
	name = "meta_author_print_method"
)

hcp(
	name = "meta_author_tag_options",
	deps = ["//code/transcompilers/unilang/options/sections/meta/other:meta_tag_existence_option",
	"author_order_method",
	"meta_author_print_method"]
)