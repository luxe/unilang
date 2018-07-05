package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "compiler", deps = [
"//code/transcompilers/unilang/dependency_graph_creator:code_graph",
"//code/transcompilers/unilang/main:program_input",
"//code/transcompilers/unilang/trevor_frontend_compiler:trevor_exporter",
"//code/transcompilers/unilang/trevor_frontend_compiler:trevor_contributors_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_exporter",
"//code/transcompilers/unilang/f2si_frontend_compiler:f2si_contributors_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:uber_exporter",
"//code/transcompilers/unilang/f2si_frontend_compiler:uber_contributors_getter",
])