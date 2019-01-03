package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "comment_style")
hcp(name = "c_line_comment_settings")
hcp(name = "c_block_comment_settings")
hcp(name = "c_comment_settings",
deps = [
	"comment_style",
	"c_line_comment_settings",
	"c_block_comment_settings"
])