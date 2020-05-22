package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "bazel_build_object")

hcp(
    name = "bazel_load_data",
    deps = [
        "//code/tools/transcompilers/unilang/options/bazel:bazel_build_object",
    ],
)

hcp(
    name = "bazel_load_db_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/bazel:bazel_load_data",
    ],
)

hcp(
    name = "build_rule_settings",
    deps = [
        "//code/tools/transcompilers/unilang/options/bazel:bazel_load_db_settings",
        "//code/tools/transcompilers/unilang/options/sections:portion_options",
    ],
)

hcp(
    name = "language_to_build_object",
    deps = [
        "//code/tools/transcompilers/unilang/options/bazel:bazel_build_object",
        "//code/utilities/formats/artifact:artifact_type",
    ],
)
