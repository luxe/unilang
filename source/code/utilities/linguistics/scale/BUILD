package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "scale_unit")

hcp(
    name = "scale_point",
    deps = [
        "//code/utilities/linguistics/scale:scale_unit",
    ],
)

hcp(
    name = "scale",
    deps = [
        "//code/utilities/linguistics/scale:scale_point",
    ],
)

hcp(
    name = "scale_getter",
    deps = [
        "//code/utilities/linguistics/scale",
    ],
)
