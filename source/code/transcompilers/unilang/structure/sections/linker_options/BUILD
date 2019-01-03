package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "link_options", deps = [
"//code/transcompilers/unilang/structure/sections/linker_options:link_option"
])

hcp(name = "link_option", deps = [
"//code/transcompilers/unilang/parser:token_value"
])