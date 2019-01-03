package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "special_json_specifier_settings", deps = [
"special_json_type",
"special_type_json_builder",
])

hcp(name = "special_json_type", deps = [
"//code/transcompilers/unilang/parser/body_parser:body_token_value",
])

hcp(name = "special_type_json_builder", deps = [
"special_json_type"
])