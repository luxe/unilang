package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "benchmarks", deps = [
"//code/tools/transcompilers/unilang/structure/model/benchmarks:benchmark",
])

hcp(name = "benchmark", deps = [
"//code/tools/transcompilers/unilang/parser:token_value",
"//code/tools/transcompilers/unilang/structure/model/benchmarks:benchmark_arg",
"//code/tools/transcompilers/unilang/structure/model/benchmarks:benchmark_setup",
"//code/tools/transcompilers/unilang/structure/model/benchmarks:benchmark_action",
])

hcp(name = "benchmark_setup", deps = [
"//code/tools/transcompilers/unilang/parser:token_value",
])

hcp(name = "benchmark_action", deps = [
"//code/tools/transcompilers/unilang/parser:token_value",
])

hcp(name = "benchmark_arg", deps = [
"//code/tools/transcompilers/unilang/parser:token_value",
])