package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

cpp_object(name = "token", deps = [
"//code/transcompilers/unilang/tokens:token_name",
"//code/transcompilers/unilang/tokens:token_group",
])

cpp_object(name = "body_token", deps = [
"//code/transcompilers/unilang/tokens:token_name",
"//code/transcompilers/unilang/tokens:token_group",
])

cpp_object(name = "global")

hcp(name = "language_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/tokens:global_token_table",
"//code/transcompilers/unilang/language-and-theme-creator:global",
"//code/transcompilers/unilang/language-and-theme-creator:shared",
"//code/utilities/converters:lib",
"//code/utilities/filesystem/paths:lib",
])

hcp(name = "reference_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/tokens:global_token_table",
"//code/transcompilers/unilang/language-and-theme-creator:global",
"//code/transcompilers/unilang/language-and-theme-creator:shared",
"//code/utilities/converters:lib",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/streams/filestreams:lib",
])

hcp(name = "shared")

hcp(name = "stylized_reference_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/tokens:global_token_table",
"//code/transcompilers/unilang/language-and-theme-creator:global",
"//code/transcompilers/unilang/language-and-theme-creator:shared",
])

hcp(name = "task_executer", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/tokens:global_token_table",
"//code/transcompilers/unilang/language-and-theme-creator:global",
"//code/transcompilers/unilang/language-and-theme-creator:reference_file_creator",
"//code/transcompilers/unilang/language-and-theme-creator:stylized_reference_file_creator",
"//code/transcompilers/unilang/language-and-theme-creator:language_file_creator",
"//code/transcompilers/unilang/language-and-theme-creator:theme_file_creator",
"//code/utilities/types/general:lib",
"//code/utilities/exits:lib",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/vectors/operators:lib",
])

hcp(name = "theme_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/tokens:global_token_table",
"//code/transcompilers/unilang/language-and-theme-creator:global",
"//code/transcompilers/unilang/language-and-theme-creator:shared",
"//code/utilities/converters:lib",
"//code/utilities/filesystem/paths:lib",
])

cc_binary(
    name = "language-and-theme-creator",
    srcs = ["main.cpp"],
    deps = ["task_executer"]
)