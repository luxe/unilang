package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")


cpp_object(name = "global")

hcp(name = "language_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/language-and-theme-creator:global",
"//code/transcompilers/unilang/language-and-theme-creator:shared",
"//code/utilities/converters:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
])

hcp(name = "reference_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/language-and-theme-creator:global",
"//code/transcompilers/unilang/language-and-theme-creator:shared",
"//code/utilities/converters:lib",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/streams/filestreams:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
"//code/utilities/filesystem/paths:lib",
])

hcp(name = "shared", deps = [
    "//code/utilities/filesystem/paths:lib"
])

hcp(name = "stylized_reference_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/language-and-theme-creator:global",
"//code/transcompilers/unilang/language-and-theme-creator:shared",
"//code/utilities/filesystem/paths:lib",
])

hcp(name = "task_executer", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/language-and-theme-creator:global",
"//code/transcompilers/unilang/language-and-theme-creator:reference_file_creator",
"//code/transcompilers/unilang/language-and-theme-creator:stylized_reference_file_creator",
"//code/transcompilers/unilang/language-and-theme-creator:language_file_creator",
"//code/transcompilers/unilang/language-and-theme-creator:theme_file_creator",
"//code/utilities/types/general:lib",
"//code/utilities/exits:lib",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/vectors/operators:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
])

hcp(name = "theme_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/language-and-theme-creator:global",
"//code/transcompilers/unilang/language-and-theme-creator:shared",
"//code/utilities/converters:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
])

cc_binary(
    name = "language-and-theme-creator",
    srcs = ["main.cpp"],
    deps = ["task_executer"]
)