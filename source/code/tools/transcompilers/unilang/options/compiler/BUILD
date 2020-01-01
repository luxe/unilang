package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "compile_unit", deps = [
"//code/tools/transcompilers/unilang/contributor:contributor",
"//code/tools/transcompilers/unilang/options:export_settings",
])

hcp(name = "compile_units", deps = ["compile_unit"])

enum_cpp(name = "chosen_exporter",
values = 
["none"
,"uber"
,"f2si"
,"trevor"
])