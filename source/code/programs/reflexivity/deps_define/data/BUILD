package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp_hdrs_derive(
    name = "dependency_specifications",
    interface_deps = [
        "//code/programs/reflexivity/deps_define/data:dependency_specification",
    ],
)

hcp_hdrs_derive(
    name = "dependency_specification",
    interface_deps = [
        "//code/programs/reflexivity/deps_define/data:build_definitions",
        "//code/programs/reflexivity/deps_define/data:dependency_location",
        "//code/programs/reflexivity/deps_define/data:patch_file",
        "//code/programs/reflexivity/deps_define/data:patch_settings",
        "//code/programs/reflexivity/deps_define/data:workspace_settings",
        "//code/programs/reflexivity/deps_define/data:repo_dependency_integration",
    ],
)

hcp_hdrs_derive(
    name = "patch_settings",
    interface_deps = [
        "//code/programs/reflexivity/deps_define/data:patch_file",
    ],
)

hcp_hdrs_derive(
    name = "dependency_specifications_getter",
    interface_deps = [
        "//code/programs/reflexivity/deps_define/data:common_patch_cmds_getter",
        "//code/programs/reflexivity/deps_define/data:dependency_specifications",
    ],
)

hcp_hdrs_derive(
    name = "common_patch_cmds_getter",
    interface_deps = [
        "//code/programs/reflexivity/deps_define/data:dependency_specifications",
        "//code/utilities/types/strings/transformers/escape:lib",
    ],
)

hcp_hdrs_derive(
    name = "dependency_location",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "build_definitions",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "workspace_settings",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "patch_file",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "repo_dependency_integration",
    interface_deps = [
        "//code/programs/reflexivity/deps_define/data:wrapper_target",
    ],
)

hcp_hdrs_derive(
    name = "wrapper_target",
    interface_deps = [
    ],
)




# Used for creating an HTML table:
hcp_hdrs_derive(
    name = "dependency_specification_table_entry",
    interface_deps = [
        "//code/programs/reflexivity/deps_define/data:build_definitions",
        "//code/programs/reflexivity/deps_define/data:dependency_location",
        "//code/programs/reflexivity/deps_define/data:patch_file",
        "//code/programs/reflexivity/deps_define/data:patch_settings",
        "//code/programs/reflexivity/deps_define/data:workspace_settings",
        "//code/programs/reflexivity/deps_define/data:repo_dependency_integration",
    ],
)