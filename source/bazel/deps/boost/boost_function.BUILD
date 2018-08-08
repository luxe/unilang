package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "function",
  includes = [
    "include/",
  ],
  hdrs = glob([
    "include/boost/**/*.hpp",
  ]),
  srcs = [
  ],
  deps = [
      "@com_github_boost_bind//:bind",
      "@com_github_boost_integer//:integer",
      "@com_github_boost_move//:move",
      "@com_github_boost_throw_exception//:throw_exception",
      "@com_github_boost_type_index//:type_index",
  ],
)
