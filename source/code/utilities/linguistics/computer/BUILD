package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "source_language",
    values =

        #Actual Languages
        [
            #UPLs
            "unilang",

            #GPLs
            "Ada",
            "BrainFuck",
            "C",
            "CPP",
            "CSharp",
            "Cobol",
            "D",
            "Elm",
            "Fortran",
            "Fsharp",
            "Go",
            "Haskell",
            "Java",
            "Kotlin",
            "Ml",
            "Nim",
            "Pascal",
            "Python",
            "Racket",
            "Rust",
            "Scala",
            "Scheme",
            "Swift",
            "HolyC",
            "Processing",

            #DSLs
            "bazel_starlark",
            "graphviz",

            #IDLs
            "ProtocolBuffers",
            "HIDL",
            "Thrift",
            "captn_proto",

            #Documentation
            "PlantUml",
            "HtmlTable",
            "Mermaid",
            "Markdown",
            "raw_text",

            #Markup
            "HTML",
            "XML",
            "BIBTEX",

            #Stlying
            "CSS",
            "SASS",
            "LESS",

            #Specification
            "ALLOY",

            #Interactive Fiction
            "INFORM_7",
        ],
)
