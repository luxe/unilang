package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")


#customly defined environments (not really a bazel concept per se)
enum_cpp(name = "run_environment",
values = [
"local"
,"remote"
])

#https://docs.bazel.build/versions/master/user-manual.html#strategy-options
enum_cpp(name = "spawn_strategy",
values = [
"default"
,"local"
,"sandboxed"
,"worker"
,"docker"
,"remote"
])

hcp(name = "build_settings", deps = [
    "//code/utilities/program/wrappers/bazel:run_environment",
    "//code/utilities/program/wrappers/bazel:spawn_strategy",
])


hcp(name = "bazel_runner", deps = [
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/program/call:lib",
    "//code/utilities/random:lib",
    "@bazel//:spawn_proto_cpp",
    "//code/utilities/formats/serialization:protobuf",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/program/wrappers/bazel:run_environment",
    "//code/utilities/program/wrappers/bazel:build_settings",
    "//code/utilities/program/inputs/flags/data:flags",
    "//code/utilities/program/inputs/flags:flag_util",
    "//code/utilities/program/wrappers/bazel/setup/config:bazel_config_settings",
])

hcp(name = "bazel_query_runner", deps = [
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/program/call:lib",
    "//code/utilities/random:lib",
    "@bazel//:spawn_proto_cpp",
    "//code/utilities/formats/serialization:protobuf",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/program/wrappers/bazel:run_environment",
])
