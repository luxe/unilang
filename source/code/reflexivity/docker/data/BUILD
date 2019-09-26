package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "apt_get_command", deps = [])
hcp(name = "apt_ppa_command", deps = [])

hcp(name = "apt_get_commands_getter", deps = [
    "//code/reflexivity/docker/data:apt_get_command",
])
hcp(name = "apt_ppa_commands_getter", deps = [
    "//code/reflexivity/docker/data:apt_ppa_command",
])