package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "compile_unit", deps = [
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/options:export_settings",
])

hcp(name = "compile_units", deps = ["compile_unit"])