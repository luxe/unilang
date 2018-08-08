package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "crc",
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
      "@com_github_boost_integer//:integer",
      "@com_github_boost_mpl//:mpl",
  ]
)
