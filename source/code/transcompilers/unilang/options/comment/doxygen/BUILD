package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cpp_object(name = "doxygen_block_style")
cpp_object(name = "doxygen_parameter_direction")
hcp(name = "doxygen_block_options",
deps = [
"//code/transcompilers/unilang/options/comment/doxygen:doxygen_block_style",
"//code/transcompilers/unilang/options/comment/doxygen/standard:standard_doxygen_style_lines"
])