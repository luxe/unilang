package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "mouse_controller",deps=[
 "//code/utilities/xdo:lib",
 "//code/utilities/data_structures/point:point",
 "//code/utilities/time/sleeping:lib",
 "//code/utilities/random:lib",
 ])

hcp(name = "mouse_resizer", deps = [
    "//code/utilities/shell:lib",
    "//code/utilities/types/strings/observers/converting:lib",
    "//code/utilities/language_basic/control_structures/looping:lib"
])