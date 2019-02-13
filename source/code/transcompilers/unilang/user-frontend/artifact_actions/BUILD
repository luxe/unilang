package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(name = "artifact_type",
values = 
["c"
,"cpp"
,"cpp_test"
,"cpp_benchmark"
,"cpp_fuzz"
,"csharp"
,"d"
,"rust"
,"processing"
,"date"
,"bazel"
,"hidl"
,"protobuf"
,"plant_uml"
,"call_graph"
,"html_table"
,"treesheets"
,"graph_easy"
,"mermaid"
,"markdown"
])

hcp(name = "artifact_guesser", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_type",
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_actions",
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_guess_settings",
"//code/utilities/types/vectors/operators:lib",
])


hcp(name = "artifact_actions", deps = [
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_type"
])

hcp(name = "artifact_guess_settings", deps = [
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_type"
])