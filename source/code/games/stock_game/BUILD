package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "task_executer", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/utilities/types/general:lib",
"//code/utilities/exits:lib",
"//code/utilities/locale:lib",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/vectors/operators:lib",
"//code/utilities/filesystem/files/creating:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
"//code/utilities/filesystem/files/getting:lib",
"//code/utilities/filesystem/paths:lib",
"//code/transcompilers/unilang/user-frontend:code_graphs_creator",
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/structure/model:inlined_structures",
"//code/transcompilers/unilang/main/root_settings:root_settings_getter",
"//code/transcompilers/unilang/compiler-frontends/markdown:markdown_str_getter",
"//code/transcompilers/unilang/self_readme:latex_template_getter",
"//code/utilities/upload:file_uploader",
"//code/transcompilers/unilang/compiler-frontends/dzslides:dzslides_exporter",
"//code/transcompilers/unilang/compiler-frontends/slidy:slidy_exporter",
"//code/utilities/chinese:chinese_translations",
"//code/utilities/time/date:lib",
"//code/utilities/time/sleeping:lib",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/strings/transformers/squeeze:lib",
"//code/utilities/screen:screen_tint_setter",
"//code/utilities/stock:stock_getter",
"//code/utilities/screen:good_bad_screen_tint_settings",
])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/games/stock_game:task_executer"]
)
