package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "method_parameter_unit_settings")
hcp(name = "method_parameter_settings",
deps = [
"//code/transcompilers/unilang/options/sections/method/parameters:method_parameter_unit_settings",
"//code/transcompilers/unilang/options/sections:notation_settings",
])