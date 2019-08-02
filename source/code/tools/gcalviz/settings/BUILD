package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

hcp(name = "gcalviz_settings", deps = [
    "//code/utilities/gcal:gcal_credentials",
    "//code/tools/gcalviz/settings:export_settings",
])

hcp(name = "default_settings_getter", deps = [
    "//code/tools/gcalviz/settings:gcalviz_settings",
    "//code/utilities/secret:secret_getter",
    "//code/utilities/filesystem/paths:lib",
])

hcp(name = "export_settings", deps = [
    "//code/tools/gcalviz/settings:export_artifact",
])
hcp(name = "export_artifact", deps = [
])