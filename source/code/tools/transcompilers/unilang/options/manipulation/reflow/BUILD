package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "comment_reflow_settings", deps = [
"//code/tools/transcompilers/unilang/options/manipulation/reflow:greedy_reflow_settings",
"//code/tools/transcompilers/unilang/options/manipulation/reflow:knuth_plass_reflow_settings",
"//code/tools/transcompilers/unilang/options/manipulation/reflow:reflow_algorithm"
])

hcp(name = "greedy_reflow_settings")
hcp(name = "knuth_plass_reflow_settings")
cpp_object(name = "reflow_algorithm")