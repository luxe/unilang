package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(name = "artifact_type",
values = 
[

#UPLs
"unilang"

#GPLs
,"c"
,"cpp"
,"cpp_boost_program_options"
,"cpp_test"
,"cpp_benchmark"
,"cpp_fuzz"
,"csharp"
,"d"
,"rust"
,"processing"
,"date"
,"bazel"
,"Ada"
,"BrainFuck"
,"Cobol"
,"Elm"
,"Fortran"
,"Fsharp"
,"Go"
,"Haskell"
,"Java"
,"Kotlin"
,"Ml"
,"Nim"
,"Pascal"
,"Python"
,"Racket"
,"Scala"
,"Scheme"
,"Swift"
,"HolyC"

#IDLs
,"hidl"
,"protobuf"
,"thrift"
,"captn_proto"

#DSLs
#...

#Documentation
,"markdown"
,"dzslides"
,"slidy"
,"plant_uml"
,"call_graph"
,"html_table"
,"treesheets"
,"graph_easy"
,"mermaid"
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


hcp(name = "to_source_language", deps = [
"//code/utilities/types/vectors/operators:lib",
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_type",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])