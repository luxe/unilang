package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "exported_dependency_options")

hcp(name = "text_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"exported_dependency_options",
"//code/transcompilers/unilang/structure:inlined_structures",
])