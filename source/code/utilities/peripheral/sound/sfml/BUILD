package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "sound",deps=[
    "@sfml//:sfml"
])

hcp(name = "sound_loader",deps=[
    "//code/utilities/peripheral/sound/sfml:sound",
    "@sfml//:sfml"
])

hcp(name = "music_loader",deps=[
    "@sfml//:sfml"
])