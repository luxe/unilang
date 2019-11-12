package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "task_executer", deps = [
    "//code/utilities/shell:lib",
    "//code/utilities/printers:lib",
    "//code/tools/external_deps_analysis:settings",
    "//code/tools/external_deps_analysis:analysis_state",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/types/sets:lib",
    "//code/utilities/types/strings/transformers/appending:lib",
    "//code/utilities/graphviz:graphviz_image_maker",
])

hcp(name = "settings", deps = [
])

hcp(name = "analysis_state", deps = [
])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/tools/external_deps_analysis:task_executer"]
)
