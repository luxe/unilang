package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "iterator",
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
      "@com_github_boost_core//:core",
      "@com_github_boost_detail//:detail",
      "@com_github_boost_mpl//:mpl",
      "@com_github_boost_static_assert//:static_assert",
  ]
)
