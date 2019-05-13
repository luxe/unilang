package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "screen_tint_setter",deps=[
"//code/utilities/streams/filestreams:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/shell:lib",
"//code/utilities/screen:rgb_section",
"//code/utilities/screen:good_bad_screen_tint_settings",
])

enum_cpp(name = "rgb_section",
values = [
"red"
,"green"
,"blue"
])

hcp(name = "good_bad_screen_tint_settings",deps=[
"//code/utilities/screen:rgb_section",
])