load("//bazel/cookbook/cpp:gtest.bzl", "gtest")

package(
    default_visibility = ["//visibility:public"],
)

gtest(
    name = "nonintrusive",
    deps = [
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/formats/json/overloads:tree_json_converters",
        "@nlohmann_json",
        "@tree",
    ],
)
