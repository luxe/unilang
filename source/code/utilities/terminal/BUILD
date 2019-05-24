package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "terminal_changer",deps=[
    "//code/utilities/terminal:good_bad_terminal_settings",
    "//code/utilities/math:math",
    "//code/utilities/shell:lib",
])

hcp(name = "good_bad_terminal_settings", deps=[
    "//code/utilities/screen/good_bad:mood_setting"
])