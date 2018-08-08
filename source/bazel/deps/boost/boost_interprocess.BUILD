package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "interprocess",
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
      "@com_github_boost_container//:container",
      "@com_github_boost_core//:core",
      "@com_github_boost_date_time//:date_time",
      "@com_github_boost_intrusive//:intrusive",
      "@com_github_boost_move//:move",
      "@com_github_boost_type_traits//:type_traits",
  ]
)
