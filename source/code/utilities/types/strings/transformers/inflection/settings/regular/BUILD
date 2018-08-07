package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "inflection")
hcp(name = "plural_inflections", deps = [
	"inflection"
])
hcp(name = "singular_inflections", deps = [
	"inflection"
])