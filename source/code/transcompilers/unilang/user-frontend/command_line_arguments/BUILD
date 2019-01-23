package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "dependency_paths")
hcp(name = "user_chosen_export_settings", deps = [
"//code/transcompilers/unilang/user-frontend:artifact_type",
"//code/transcompilers/unilang/options/compiler:chosen_exporter"
])