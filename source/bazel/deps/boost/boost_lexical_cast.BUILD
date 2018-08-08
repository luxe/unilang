package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "lexical_cast",
  includes = [
      "include/",
  ],
  hdrs = glob([
      "include/boost/**/*.hpp",
  ]),
  srcs = [
  ],
  deps = [
      "@com_github_boost_array//:array",
      "@com_github_boost_container//:container",
      "@com_github_boost_integer//:integer",
      "@com_github_boost_move//:move",
      "@com_github_boost_numeric_conversion//:numeric_conversion",
      "@com_github_boost_range//:range",
  ]
)
