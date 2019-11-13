package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")

hcp(name = "task_executer", deps = [
    "//code/tools/shared_object_trace/program_options:lib",
    "//code/utilities/exits:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/filesystem/files/getting:lib",
    "//code/tools/shared_object_trace:file_and_type",
    "//code/utilities/filesystem/files/observers/other:lib",
    "//code/utilities/types/strings/observers/other:lib",
])

hcp(name = "file_and_type", deps = [
])

distributable_cpp_main(
    name = "shared_object_trace",
    deps = [
        "//code/tools/shared_object_trace:task_executer",
        "//code/tools/shared_object_trace/program_options:lib",
    ],
    description = "track shared objects from 3rd party libraries to other third party libaries that use them",
    depends = [
    ],
)