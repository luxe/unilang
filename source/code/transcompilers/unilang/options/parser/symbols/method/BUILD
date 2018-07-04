package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "token_method_argument_attribute_settings")

hcp(name = "token_method_attribute_settings",
deps = [
"token_method_argument_attribute_settings",
"token_method_inheritance_attribute_settings",
"//code/transcompilers/unilang/options/parser/symbols/shared:token_access_attribute_settings",
])

hcp(name = "token_method_inheritance_attribute_settings")

hcp(name = "token_method_name_special_name_meaning")