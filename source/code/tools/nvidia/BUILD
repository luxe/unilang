package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

cpp_main(
    name = "main",
    deps = [
        "//code/tools/nvidia:arch_pruner",
    ],
)

hcp(
    name = "arch_pruner",
    deps = [
        "//code/utilities/formats/compression:lib",
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/formats/objects:cuda_arch_symbol_counter",
        "//code/utilities/filesystem/files/observers:filename_size_printer",
    ],
)
