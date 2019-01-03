package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="input_file_settings")
hcp(name="macro_resolving_settings")
hcp(name="parser_settings",
deps = [
"macro_resolving_settings",
"input_file_settings",
"tokenize_settings",
])
hcp(name="tokenize_settings",
deps = [
"//code/transcompilers/unilang/options/parser/symbols:token_attribute_settings"
])
