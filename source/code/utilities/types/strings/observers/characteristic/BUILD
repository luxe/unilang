package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = ["//code/utilities/types/char:lib"]
)

hcp(name="english_number_to_integral_converter",   deps = [
  "//code/utilities/types/vectors/observers:lib",
  "//code/utilities/types/strings/transformers/casing:lib"
])

hcp(name="is_english_number_checker",   deps = [
  "//code/utilities/types/vectors/observers:lib",
  "//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name="is_month_word_checker",   deps = [
  "//code/utilities/types/vectors/observers:lib",
  "//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name="is_weekday_checker",   deps = [
  "//code/utilities/types/vectors/observers:lib",
  "//code/utilities/types/strings/transformers/casing:lib",
])

hcp(name="spirit_numeric_checker",   deps = [
  "@boost//:spirit",
  "@boost//:phoenix",
  "@boost//:range",
  "@boost//:variant",
  "@boost//:foreach",
])

