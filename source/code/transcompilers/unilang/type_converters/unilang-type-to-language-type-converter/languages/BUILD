package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "equivalent_language_types", deps = [
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages/language_type:language_type",
"//code/utilities/types:tri_bool",
"//code/transcompilers/unilang/options/self_describe_type:inferred_type_properties",
])

enum_cpp(name = "source_language",
values = 

#Actual Languages
["Ada"
,"BrainFuck"
,"C"
,"CPP"
,"CSharp"
,"Cobol"
,"D"
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
,"Rust"
,"Scala"
,"Scheme"
,"Swift"
,"HolyC"
,"Processing"

#IDLs
,"ProtocolBuffers"
,"HIDL"
,"Thrift"

#Documentation
,"PlantUml"
,"HtmlTable"
,"Mermaid"
,"Markdown"
])


