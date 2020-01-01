package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
	name = "begin_include_guard_options",
)

hcp(
	name = "end_include_guard_options",
	deps = [
	"//code/tools/transcompilers/unilang/options/comment/language_default:comment_style"
])

hcp(
	name = "include_guard_options",
	deps = [
	"//code/tools/transcompilers/unilang/options/sections/include_guard:begin_include_guard_options",
	"//code/tools/transcompilers/unilang/options/sections/include_guard:end_include_guard_options",
	"//code/utilities/types/strings/transformers/casing:case_format_style"
])