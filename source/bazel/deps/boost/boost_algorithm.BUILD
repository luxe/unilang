package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "algorithm",
  includes = [
    "include/",
  ],
  hdrs = glob([
    "include/boost/**/*.hpp",
  ]),
  srcs = [
  ],
  deps = [
      "@com_github_boost_config//:config",
      "@com_github_boost_function//:function",
      "@com_github_boost_mpl//:mpl",
      "@com_github_boost_range//:range",
  ],
)
