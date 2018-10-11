package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "comment_reflow_settings", deps = [
"//code/transcompilers/unilang/options/manipulation/reflow:greedy_reflow_settings",
"//code/transcompilers/unilang/options/manipulation/reflow:reflow_algorithm"
])

hcp(name = "greedy_reflow_settings")
hcp(name = "knuth_plass_reflow_settings")