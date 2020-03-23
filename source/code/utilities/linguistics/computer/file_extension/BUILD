package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "file_extension_getter", deps = [
"//code/utilities/linguistics/computer:source_language",
"//code/utilities/linguistics/computer/file_extension/lookup_table:file_extension_lookup_table_getter",
"//code/utilities/types/map:lib",
"//code/utilities/formats/artifact:artifact_type",
"//code/utilities/formats/artifact:to_source_language",
])

