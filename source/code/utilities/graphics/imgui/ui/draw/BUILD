package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="color",deps = [])
hcp(name="position",deps = [])
hcp(name="imgui_type_utility", deps = [
"//code/utilities/graphics/imgui/ui/draw:color",
"//code/utilities/graphics/imgui:mechanics",
])