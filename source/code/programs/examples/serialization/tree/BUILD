load("//bazel/rules/cpp:gtest.bzl", "gtest")

package(
    default_visibility = ["//visibility:public"],
)

gtest(
    name = "nonintrusive",
    deps = [
        "//code/utilities/deps/external/tree:lib",
        "//code/utilities/formats/json/converters:lib",
        "//code/utilities/formats/json/overloads:tree_json_converters",
        "@nlohmann_json",
    ],
)
