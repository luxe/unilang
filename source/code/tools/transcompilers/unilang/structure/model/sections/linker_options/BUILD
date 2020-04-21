package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "link_options", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/linker_options:link_option"
])

hcp(name = "link_option", deps = [
"//code/tools/transcompilers/unilang/parser:token_value"
])