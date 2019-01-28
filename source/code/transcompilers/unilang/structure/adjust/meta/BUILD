package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "meta_adjuster", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/options/manipulation:struct_manipulation_settings",
"//code/transcompilers/unilang/structure/adjust:comment_adjuster",
])