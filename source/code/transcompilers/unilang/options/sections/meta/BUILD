package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "meta_blank_line_options")
hcp(name = "meta_classification_options")
hcp(name = "meta_contract_number_options")
hcp(name = "meta_distribution_statement_options")
hcp(name = "meta_external_link_options",
	deps = ["//code/transcompilers/unilang/options/sections/meta/other:meta_tag_existence_option"])
hcp(name = "meta_file_tag_options")
hcp(name = "meta_generic_note_options")
hcp(name = "meta_organization_options")
hcp(name = "meta_project_name_options")
hcp(name = "meta_watermark_settings")
cpp_object(name = "meta_section_name")
hcp(name = "meta_task_order_options")
hcp(name = "meta_options",
	deps = [
	"//code/transcompilers/unilang/options/sections/meta:meta_file_tag_options",
	"//code/transcompilers/unilang/options/sections/meta:meta_generic_note_options",
	"//code/transcompilers/unilang/options/sections/meta/other:meta_brief_tag_options",
	"//code/transcompilers/unilang/options/sections/meta/other:meta_details_tag_options",
	"//code/transcompilers/unilang/options/sections/meta:meta_external_link_options",
	"//code/transcompilers/unilang/options/sections/meta/copyright:meta_copyright_tag_options",
	"//code/transcompilers/unilang/options/sections/meta/other:meta_group_name_tag_options",
	"//code/transcompilers/unilang/options/sections/meta/author:meta_author_tag_options",
	"//code/transcompilers/unilang/options/sections/meta/other:meta_bug_tag_options",
	"//code/transcompilers/unilang/options/sections/meta/other:meta_warning_tag_options",
	"//code/transcompilers/unilang/options/sections/meta:meta_blank_line_options",
	"//code/transcompilers/unilang/options/sections/meta:meta_classification_options",
	"//code/transcompilers/unilang/options/sections/meta:meta_contract_number_options",
	"//code/transcompilers/unilang/options/sections/meta:meta_distribution_statement_options",
	"//code/transcompilers/unilang/options/sections/meta:meta_task_order_options",
	"//code/transcompilers/unilang/options/sections/meta:meta_project_name_options",
	"//code/transcompilers/unilang/options/sections/meta:meta_section_name",
	"//code/transcompilers/unilang/options/sections/meta:meta_watermark_settings",
	"//code/transcompilers/unilang/options/sections/meta:meta_organization_options",
	"//code/transcompilers/unilang/options/sections/meta/organizations:organization",
	"//code/transcompilers/unilang/options/comment:comment_settings",
	])