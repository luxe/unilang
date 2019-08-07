package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

hcp(name = "bazel_refresher", deps = [
"//code/utilities/filesystem/paths:lib",
"//code/reflexivity/conversion_test:bazel_conversion_tests",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/filesystem/files/creating:lib",
"//code/utilities/filesystem/files/deleting:lib",
"//code/utilities/types/vectors/converters:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/reflexivity/conversion_test:test_getter",
"//code/reflexivity:readme_creator",
"//code/transcompilers/unilang/file_extension_getter:file_extension_getter",
])

hcp(name = "readme_creator", deps = [
"//code/utilities/filesystem/paths:lib",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/filesystem/files/creating:lib",
])

cpp_main(
    name = "reflexive_refresh",
    deps = [
        "//code/reflexivity:bazel_refresher",
        "//code/reflexivity/docker:dockerfile_refresher",
        "//code/utilities/locale:lib"
    ],
)