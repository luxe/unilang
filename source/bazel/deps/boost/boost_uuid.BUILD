package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "uuid",
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
      "@com_github_boost_core//:core",
      "@com_github_boost_iterator//:iterator",
      "@com_github_boost_random//:random",
      "@com_github_boost_smart_ptr//:smart_ptr",
      "@com_github_boost_static_assert//:static_assert",
      "@com_github_boost_throw_exception//:throw_exception",
      "@com_github_boost_type_traits//:type_traits",
  ]
)
