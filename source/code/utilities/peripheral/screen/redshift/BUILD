package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "redshift_settings",deps=[
])

hcp(name = "redshift_command_getter",deps=[
    "//code/utilities/peripheral/screen/redshift:redshift_settings",
])
