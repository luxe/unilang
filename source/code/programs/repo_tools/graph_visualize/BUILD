package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:distributable_main.bzl", "distributable_cpp_main")

distributable_cpp_main(
    name = "main",
    depends = [
    ],
    description = "visualize bazel build graph",
    deps = [
        "//code/programs/repo_tools/graph_visualize:task_executer",
        "//code/programs/repo_tools/graph_visualize/program_options:lib",
    ],
)

hcp_hdrs_derive(
    name = "task_executer",
    interface_deps = [
        "//code/utilities/build/build_repo_establisher",
        "//code/utilities/build/build_repo_establisher:build_repo_settings",
        "//code/utilities/build/profiler:branch_profile_compilation_timer",
        "//code/utilities/build/profiler/data:profile_results",
        "//code/utilities/build/profiler/data:profile_settings",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/math",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/wrappers/bazel/query:bazel_query_runner",
        "//code/utilities/program/wrappers/git:branch_switcher",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/queue:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/program/wrappers/bazel:bazel_runner",
        "//code/utilities/formats/serialization:protobuf",
        "//code/utilities/program/wrappers/bazel/query:bazel_aquery_runner",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/formats/gexf/data:gexf_data",
        "//code/utilities/formats/gexf:gexf_formatter",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/data_structures/graph/basic:timed_connection",
    ],
    deps = [
    "//code/programs/repo_tools/graph_visualize/program_options:lib",
    ]
)