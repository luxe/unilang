package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "actionable_code_graphs", deps = [
    "//code/tools/transcompilers/unilang/user-frontend/action_graphs:actionable_code_graph",
    "//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_actions",
])
hcp(name = "actionable_code_graph", deps = [
    "//code/tools/transcompilers/unilang/structure/model:structure",
    "//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
    "//code/utilities/data_structures/unique_vertex_graph:lib",
    "//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_actions",
])
hcp(name = "code_graphs_to_actionable_graphs", deps = [
    "//code/tools/transcompilers/unilang/user-frontend/action_graphs:actionable_code_graphs",
    "//code/tools/transcompilers/unilang/main:program_input",
    "//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
    "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
    "//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_guesser",
    
])