package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "code_graph", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/utilities/data_structures/unique_vertex_graph:lib",
])

hcp(name = "seen_structure_dependencies", deps = [
])


hcp(name = "dependency_graph_creator", deps = [
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/parser:structure_creator",
"//code/transcompilers/unilang/dependency_graph_creator:seen_structure_dependencies",
"//code/transcompilers/unilang/dependency_graph_creator:dependency_looker_upper",
"//code/transcompilers/unilang/user-frontend:fully_read_file",
"//code/utilities/types/sets:lib",
"//code/transcompilers/unilang/structure:inlined_structures",
])

hcp(name = "dependency_looker_upper", deps = [
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/parser:structure_creator",
"//code/transcompilers/unilang/dependency_graph_creator:seen_structure_dependencies",
"//code/utilities/filesystem/files/observers/lstat_wrap:lib",
"//code/utilities/converters:lib",
])