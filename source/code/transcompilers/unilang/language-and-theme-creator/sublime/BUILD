package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")


cpp_object(name = "global")

hcp(name = "language_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:global",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:shared",
"//code/utilities/converters:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
])

hcp(name = "reference_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:global",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:shared",
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
"//code/transcompilers/unilang/language-and-theme-creator/sublime:global",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:shared",
"//code/utilities/filesystem/paths:lib",
])

hcp(name = "unilang_file_creator", deps = [
"//code/transcompilers/unilang/language-and-theme-creator/sublime:reference_file_creator",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:stylized_reference_file_creator",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:language_file_creator",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:theme_file_creator",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:global",
])

hcp(name = "theme_file_creator", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:global",
"//code/transcompilers/unilang/language-and-theme-creator/sublime:shared",
"//code/utilities/converters:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
])
