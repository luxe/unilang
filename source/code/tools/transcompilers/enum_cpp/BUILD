package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "enum",
)

hcp(
    name = "enum_cpp_maker",
    deps = [
        "enum",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)

cc_binary(
    name = "enum_cpp",
    srcs = ["main.cc"],
    deps = [
        "enum",
        "enum_cpp_maker",
        "//code/tools/transcompilers/enum_cpp/program_options:lib",
    ],
)
