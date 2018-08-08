package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "accumulators",
  includes = [
      "include/",
  ],
  hdrs = glob([
      "include/boost/**/*.hpp",
  ]),
  srcs = [
  ],
  deps = [
      "@com_github_boost_assert//:assert",
      "@com_github_boost_config//:config",
      "@com_github_boost_concept_check//:concept_check",
      "@com_github_boost_fusion//:fusion",
      "@com_github_boost_mpl//:mpl",
      "@com_github_boost_parameter//:parameter",
      "@com_github_boost_range//:range",
  ]
)
