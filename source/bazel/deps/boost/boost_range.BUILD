package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "range",
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
      "@com_github_boost_concept_check//:concept_check",
      "@com_github_boost_config//:config",
      "@com_github_boost_iterator//:iterator",
      "@com_github_boost_preprocessor//:preprocessor",
      "@com_github_boost_type_traits//:type_traits",
      "@com_github_boost_utility//:utility",
  ]
)
