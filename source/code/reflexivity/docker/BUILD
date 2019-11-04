package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "dockerfile_refresher", deps = [
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/filesystem/files/creating:lib",
"//code/utilities/filesystem/files/deleting:lib",
"//code/utilities/types/vectors/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/reflexivity/docker/data:apt_get_command",
"//code/transcompilers/unilang/file_extension_getter:file_extension_getter",
"//code/reflexivity/docker/data:docker_settings_getter",
"//code/reflexivity/docker/data:docker_settings",
"//code/reflexivity/comment:generated_comment_getter",
])