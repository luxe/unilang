package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

# various kinds of artifact types that programs can produce
# for example, we would expect the unilang-transcompilation framework
# to be able to produce artifacts of all of these types.
# artifacts have no correlation to number of files, actual content, or file extension
# although based on the name, you can likely infer what these properties ought to be.
enum_cpp(
    name = "artifact_type",
    values =
        [

            #UPLs
            "unilang",

            #GPLs
            "c",
            "cpp",
            "cpp_boost_program_options",
            "cpp_test",
            "cpp_benchmark",
            "cpp_fuzz",
            "java",
            "java_test",
            "java_benchmark",
            "java_fuzz",
            "csharp",
            "d",
            "rust",
            "processing",
            "date",
            "bazel",
            "Ada",
            "BrainFuck",
            "Cobol",
            "Elm",
            "Fortran",
            "Fsharp",
            "Go",
            "Haskell",
            "Kotlin",
            "Ml",
            "Nim",
            "Pascal",
            "Python",
            "Racket",
            "Scala",
            "Scheme",
            "Swift",
            "HolyC",
            "Futhark",

            #IDLs
            "hidl",
            "protobuf",
            "thrift",
            "captn_proto",

            #DSLs
            #...

            #Documentation / Markdown
            "markdown",
            "dzslides",
            "slidy",
            "plant_uml",
            "call_graph",
            "html_table",
            "treesheets",
            "graph_easy",
            "mermaid",
            "bibtex",
        ],
)

hcp(
    name = "to_source_language",
    deps = [
        "//code/utilities/formats/artifact:artifact_type",
        "//code/utilities/linguistics/computer:source_language",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
