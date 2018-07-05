package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "compile_unit", deps = [
"//code/transcompilers/unilang/contributor:contributor",
])

hcp(name = "compile_units", deps = ["compile_unit"])