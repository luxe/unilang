package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "arch_prune_settings",
    deps = [
    ],
)

hcp(
    name = "cuda_arch_prune_analyzer",
    deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers:filename_size_printer",
        "//code/utilities/formats/compression:lib",
        "//code/utilities/formats/objects:arch_prune_settings",
        "//code/utilities/formats/objects:cuda_arch_pruner",
        "//code/utilities/formats/objects:cuda_arch_symbol_counter",
        "//code/utilities/random/files:random_files",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)

hcp(
    name = "cuda_arch_symbol_counter",
    deps = [
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/wrappers/cuobjdump:cuobjdump_finder",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/vectors/creators:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "cuda_arch_pruner",
    deps = [
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/program/wrappers/nvprune:nvprune_finder",
        "//code/utilities/random/files:random_files",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/vectors/creators:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "tgz_cuda_arch_pruner",
    deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/filesystem/files/observers:filename_size_printer",
        "//code/utilities/formats/compression:lib",
        "//code/utilities/formats/objects:cuda_arch_prune_analyzer",
        "//code/utilities/formats/objects:cuda_arch_pruner",
        "//code/utilities/formats/objects:cuda_arch_symbol_counter",
        "//code/utilities/random/files:random_files",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)
