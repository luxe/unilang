load("//bazel/cookbook/cpp:gtest.bzl", "gtest")
package(
    default_visibility = ["//visibility:public"],
)

gtest(name = "boost_int",
      deps = ["@boost//:serialization",]
)

gtest(name = "cereal_int",
      deps = ["@cereal//:main"]
)