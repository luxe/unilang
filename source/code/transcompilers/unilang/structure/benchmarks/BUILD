package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "benchmarks", deps = [
"//code/transcompilers/unilang/structure/benchmarks:benchmark",
])

hcp(name = "benchmark", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/benchmarks:benchmark_arg",
"//code/transcompilers/unilang/structure/benchmarks:benchmark_setup",
"//code/transcompilers/unilang/structure/benchmarks:benchmark_action",
])

hcp(name = "benchmark_setup", deps = [
"//code/transcompilers/unilang/parser:token_value",
])

hcp(name = "benchmark_action", deps = [
"//code/transcompilers/unilang/parser:token_value",
])

hcp(name = "benchmark_arg", deps = [
"//code/transcompilers/unilang/parser:token_value",
])