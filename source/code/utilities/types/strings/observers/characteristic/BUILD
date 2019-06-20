package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = ["//code/utilities/types/char:lib"]
)

hcp(name="spirit_numeric_checker",   deps = [
  "@boost//:spirit",
  "@boost//:phoenix",
  "@boost//:range",
  "@boost//:variant",
  "@boost//:foreach",
])

