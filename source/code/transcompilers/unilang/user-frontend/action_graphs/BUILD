package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "actionable_code_graphs", deps = [
    "//code/transcompilers/unilang/user-frontend/action_graphs:actionable_code_graph",
    "//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_actions",
])
hcp(name = "actionable_code_graph", deps = [
    "//code/transcompilers/unilang/structure/model:structure",
    "//code/transcompilers/unilang/user-frontend/action_graphs:actionable_structure",
    "//code/utilities/data_structures/unique_vertex_graph:lib",
])
hcp(name = "actionable_structure", deps = [
    "//code/transcompilers/unilang/structure/model:structure",
    "//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_actions",
])
hcp(name = "code_graphs_to_actionable_graphs", deps = [
    "//code/transcompilers/unilang/user-frontend/action_graphs:actionable_code_graphs",
    "//code/transcompilers/unilang/main:program_input",
    "//code/transcompilers/unilang/dependency_graph_creator:code_graph",
    "//code/transcompilers/unilang/structure/model:inlined_structures",
    
])