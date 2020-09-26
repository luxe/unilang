load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")

hcp(
    name = "a",
    deps = [],
)

hcp(
    name = "b",
    deps = [],
)

hcp(
    name = "root",
    deps = [
        "//code/hello_world/variant:a",
        "//code/hello_world/variant:b",
    ],
)

cpp_main(
    name = "main",
    deps = [
        "//code/hello_world/variant:root",
        "//code/utilities/types/variant:lib",
    ],
)
