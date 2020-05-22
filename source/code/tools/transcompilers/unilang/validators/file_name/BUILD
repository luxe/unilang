package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "filename_exception",
    deps = [
        "//code/tools/transcompilers/unilang/parser/tokenizer/file_marker",
    ],
)

hcp(name = "filename_validation_settings")

hcp(
    "filename_validator",
    deps = [
        "//code/tools/transcompilers/unilang/validators/file_name:filename_exception",
        "//code/tools/transcompilers/unilang/validators/file_name:filename_validation_settings",
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
