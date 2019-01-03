package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cpp_object(name = "method_sort_algorithm_types")
hcp(name="method_sort_algorithms", deps=[
"//code/transcompilers/unilang/options/sections/method/sorting/method_sort_algorithms:method_sort_algorithm_types",
"//code/transcompilers/unilang/options/sections/method/sorting:method_subgroup_tag_settings"
])