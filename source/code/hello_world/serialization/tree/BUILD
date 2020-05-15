load("//bazel/cookbook/cpp:gtest.bzl", "gtest")
package(
    default_visibility = ["//visibility:public"],
)

gtest(name = "nonintrusive",
      deps = [
      "@tree//:tree",
      "@nlohmann_json//:nlohmann_json",
      "//code/utilities/formats/json/overloads:tree_json_converters"
      ]
)