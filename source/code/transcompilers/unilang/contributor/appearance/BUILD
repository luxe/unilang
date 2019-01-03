package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object("gender")
cpp_object("species")
hcp(name = "contributor_appearance", deps = [
"//code/transcompilers/unilang/contributor/appearance:species",
"//code/transcompilers/unilang/contributor/appearance:gender"
])