package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="label_face", deps = [
    "//code/utilities/graphics/imgui/ui/draw/label/complexity/faced/regular:label_settings",
])

hcp(name="positioned_faced_label", deps = [
    "//code/utilities/data_structures/position:position",
    "//code/utilities/graphics/imgui/ui/draw/label/complexity/faced:label_face",
])


hcp(name="faced_label", deps = [
    "//code/utilities/data_structures/position:position",
    "//code/utilities/graphics/imgui/ui/draw/label/complexity/faced:label_face",
])
