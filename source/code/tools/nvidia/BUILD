package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

cpp_main(
    name = "main",
    deps = [
        "//code/tools/nvidia:arch_pruner",
        "//code/utilities/formats/objects:arch_prune_settings",
        "//code/tools/nvidia/program_options:lib",
    ],
)


hcp(
    name = "arch_pruner",
    deps = [
        "//code/utilities/formats/compression:lib",
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/formats/objects:cuda_arch_symbol_counter",
        "//code/utilities/filesystem/files/observers:filename_size_printer",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
        "//code/utilities/random/files:random_files",
        "//code/utilities/formats/objects:cuda_arch_pruner",
        "//code/utilities/formats/objects:cuda_arch_prune_analyzer",
    ],
)
