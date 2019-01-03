package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cpp_object("protocol_buffer_version_number")
hcp(name = "protocol_buffer_version_settings", deps = [
"//code/transcompilers/unilang/options/language-specific/protocol_buffer_settings/version:protocol_buffer_version_number"
])