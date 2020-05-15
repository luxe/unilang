package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "code_graph", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/utilities/data_structures/graph/unique_vertex_graph:lib",
])

hcp(name = "seen_structure_dependencies", deps = [
])


hcp(name = "dependency_graph_creator", deps = [
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/parser:structure_creator",
"//code/tools/transcompilers/unilang/dependency_graph_creator:seen_structure_dependencies",
"//code/tools/transcompilers/unilang/dependency_graph_creator:dependency_looker_upper",
"//code/tools/transcompilers/unilang/user-frontend:fully_read_file",
"//code/utilities/types/sets:lib",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
])

hcp(name = "dependency_looker_upper", deps = [
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/parser:structure_creator",
"//code/tools/transcompilers/unilang/dependency_graph_creator:seen_structure_dependencies",
"//code/utilities/filesystem/files/observers/lstat_wrap:lib",
"//code/utilities/types/converters:lib",
])