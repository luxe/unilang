load("//bazel/cookbook/cpp:gtest.bzl", "gtest")
package(
    default_visibility = ["//visibility:public"],
)

gtest(name = "boost_non_class_int",
      deps = ["@boost//:serialization",]
)

gtest(name = "cereal_non_class_int",
      deps = ["@cereal//:main"]
)

gtest(name = "boost_class_int_intrusive",
      deps = ["@boost//:serialization",]
)
gtest(name = "boost_class_int_nonintrusive",
      deps = ["@boost//:serialization",]
)