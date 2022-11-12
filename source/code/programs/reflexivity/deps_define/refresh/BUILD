package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp_hdrs_derive(
    name = "deps_definition_refresher",
    interface_deps = [
        "//code/programs/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/programs/reflexivity/deps_define/refresh/parts:build_files_creator",
        "//code/programs/reflexivity/deps_define/refresh/parts:get_files_creator",
        "//code/programs/reflexivity/deps_define/refresh/parts:main_deps_file_creator",
        "//code/programs/reflexivity/deps_define/refresh/parts:workspace_files_creator",
        "//code/programs/reflexivity/deps_define/refresh/parts:wrapper_target_creator",
        "//code/programs/reflexivity/deps_define/refresh/parts:deps_table_creator",
        "//code/programs/reflexivity/deps_define/refresh/parts:deps_config_creator",
    ],
)
