package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "inflection")
hcp(name = "plural_inflections", deps = [
	"inflection"
])
hcp(name = "singular_inflections", deps = [
	"inflection"
])