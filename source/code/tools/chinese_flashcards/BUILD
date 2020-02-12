package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "task_executer", deps = [
"//code/tools/transcompilers/unilang/tokens:generic_token",
"//code/utilities/types/general:lib",
"//code/utilities/program/common_actions/exits:lib",
"//code/utilities/program/common_actions/locale:lib",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/vectors/operators:lib",
"//code/utilities/filesystem/files/creating:lib",
"//code/tools/transcompilers/unilang/tokens:get_tokens",
"//code/utilities/filesystem/files/getting:lib",
"//code/utilities/filesystem/paths:lib",
"//code/tools/transcompilers/unilang/user-frontend:code_graphs_creator",
"//code/tools/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
"//code/tools/transcompilers/unilang/main/root_settings:root_settings_getter",
"//code/tools/transcompilers/unilang/compiler-frontends/markdown:markdown_str_getter",
"//code/utilities/output/upload:file_uploader",
"//code/tools/transcompilers/unilang/compiler-frontends/dzslides:dzslides_exporter",
"//code/tools/transcompilers/unilang/compiler-frontends/slidy:slidy_exporter",
"//code/utilities/linguistics/chinese:chinese_translations",
"//code/utilities/time/date:lib",
])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/tools/chinese_flashcards:task_executer"]
)
