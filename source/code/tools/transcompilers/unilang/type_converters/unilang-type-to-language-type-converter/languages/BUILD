package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "cross_language_type", deps = [
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages/language_type:language_type",
"//code/utilities/types:tri_bool",
"//code/tools/transcompilers/unilang/options/self_describe_type:inferred_type_properties",
])

enum_cpp(name = "source_language",
values = 

#Actual Languages
[
#UPLs
"unilang"

#GPLs
,"Ada"
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

#DSLs
,"bazel_skylark"
,"graphviz"

#IDLs
,"ProtocolBuffers"
,"HIDL"
,"Thrift"
,"captn_proto"

#Documentation
,"PlantUml"
,"HtmlTable"
,"Mermaid"
,"Markdown"
,"raw_text"

#Markup
,"HTML"
,"XML"

#Stlying
,"CSS"
,"SASS"
,"LESS"


])


