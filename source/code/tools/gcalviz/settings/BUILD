package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

hcp(name = "gcalviz_settings", deps = [
    "//code/utilities/gcal:gcal_credentials"
])

hcp(name = "default_settings_getter", deps = [
    "//code/tools/gcalviz/settings:gcalviz_settings",
    "//code/utilities/secret:secret_getter"
])