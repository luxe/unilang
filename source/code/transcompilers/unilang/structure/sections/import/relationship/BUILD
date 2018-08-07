package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "type_relationships", deps = [
])

hcp(name = "import_relationship", deps = [
"//code/transcompilers/unilang/parser:token_value",
"type_relationships"
])