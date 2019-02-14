package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "subgroup_methods", deps = [
"//code/transcompilers/unilang/structure/model/sections/method:method_item"
])

hcp(name = "subgroup_sorted_methods", deps = [
"subgroup_methods"
])