package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "gcalviz_settings", deps = [
    "//code/utilities/web/endpoints/gcal:gcal_credentials",
    "//code/tools/gcalviz/settings:export_settings",
])

hcp(name = "default_settings_getter", deps = [
    "//code/tools/gcalviz/settings:gcalviz_settings",
    "//code/utilities/personal/secret:secret_getter",
    "//code/utilities/filesystem/paths:lib",
])

hcp(name = "export_settings", deps = [
    "//code/tools/gcalviz/settings:export_artifact",
])
hcp(name = "export_artifact", deps = [
])