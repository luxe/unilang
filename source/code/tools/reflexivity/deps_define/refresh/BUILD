package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp(
    name = "deps_definition_refresher",
    deps = [
        "//code/tools/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/tools/reflexivity/deps_define/refresh/parts:get_files_creator",
        "//code/tools/reflexivity/deps_define/refresh/parts:main_deps_file_creator",
    ],
)
