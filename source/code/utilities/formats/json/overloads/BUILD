package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

cpp_object(name = "tree_json_converters", 
    deps = [
      "@tree//:tree",
      "@nlohmann_json//:nlohmann_json",
      "//code/utilities/types/tree/converters:depth_list"
      ]
)