package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "artifact_guesser", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/utilities/formats/artifact:artifact_type",
"//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_actions",
"//code/tools/transcompilers/unilang/user-frontend/artifact_actions:artifact_guess_settings",
"//code/utilities/types/vectors/operators:lib",
])


hcp(name = "artifact_actions", deps = [
"//code/utilities/formats/artifact:artifact_type"
])

hcp(name = "artifact_guess_settings", deps = [
"//code/utilities/formats/artifact:artifact_type"
])