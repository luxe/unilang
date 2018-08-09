package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "variant",
  includes = [
    "include/",
  ],
  hdrs = glob([
    "include/boost/**/*.hpp",
  ]),
  srcs = [
  ],
  deps = [
    "@com_github_boost_type_index//:type_index",
    "@com_github_boost_type_traits//:type_traits",
    "@com_github_boost_config//:config",
    "@com_github_boost_move//:move",
  ]
)
