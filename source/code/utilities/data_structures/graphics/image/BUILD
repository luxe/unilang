load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

package(default_visibility = ["//visibility:public"])

cpp_object(name = "image",
    deps = [
    "//code/utilities/data_structures/position:position",
    "@stb"
    ],
)

cpp_object(name = "positioned_image",
    deps = [
    "//code/utilities/data_structures/position:position",
    "@stb"
    ],
)