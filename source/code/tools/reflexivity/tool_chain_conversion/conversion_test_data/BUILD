package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "bazel_conversion_test",
    deps = [
        "//code/tools/reflexivity/tool_chain_conversion/conversion_test_data:bazel_conversion_test_file_contents",
        "//code/utilities/formats/artifact:artifact_type",
    ],
)

hcp(
    name = "bazel_conversion_tests",
    deps = [
        "//code/tools/reflexivity/tool_chain_conversion/conversion_test_data:bazel_conversion_test",
    ],
)

hcp(
    name = "bazel_conversion_test_file_contents",
    deps = [
    ],
)

hcp(
    name = "test_getter",
    deps = [
        "//code/tools/reflexivity/tool_chain_conversion/conversion_test_data:bazel_conversion_tests",
        "//code/tools/transcompilers/unilang/tokens:get_tokens",
        "//code/tools/transcompilers/unilang/tokens/builder:token_builder",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
