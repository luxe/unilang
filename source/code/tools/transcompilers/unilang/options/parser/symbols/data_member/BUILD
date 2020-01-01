package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "token_data_member_state_attribute_settings")
hcp(name = "token_data_member_attribute_settings",
deps = [
"//code/transcompilers/unilang/options/parser/symbols/shared:token_access_attribute_settings",
"token_data_member_state_attribute_settings"
])