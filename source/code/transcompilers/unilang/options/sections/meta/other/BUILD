package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(
	name = "meta_tag_existence_option",
)

hcp(
	name = "meta_warning_tag_options",
	deps = ["meta_tag_existence_option"]
)

hcp(
	name = "meta_group_name_tag_options",
	deps = ["meta_tag_existence_option"]
)

hcp(
	name = "meta_details_tag_options",
	deps = ["meta_tag_existence_option"]
)

hcp(
	name = "meta_bug_tag_options",
	deps = ["meta_tag_existence_option"]
)

hcp(
	name = "meta_brief_tag_options",
	deps = ["meta_tag_existence_option"]
)