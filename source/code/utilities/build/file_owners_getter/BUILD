package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(
    name = "file_owners_getter",
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/other_language:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
    ],
)