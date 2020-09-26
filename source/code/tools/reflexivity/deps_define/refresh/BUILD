package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "deps_definition_refresher",
    deps = [
        "//code/tools/reflexivity/comment:generated_comment_getter",
        "//code/tools/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/tools/reflexivity/deps_define/refresh/parts:get_files_creator",
        "//code/tools/reflexivity/deps_define/refresh/parts:main_deps_file_creator",
        "//code/tools/reflexivity/tool_chain_conversion:readme_creator",
        "//code/tools/reflexivity/tool_chain_conversion/conversion_test_data:bazel_conversion_tests",
        "//code/tools/reflexivity/tool_chain_conversion/conversion_test_data:test_getter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/file_extension:file_extension_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/vectors/converters:lib",
    ],
)
