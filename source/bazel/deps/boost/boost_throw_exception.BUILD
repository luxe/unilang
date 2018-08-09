package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "throw_exception",
  includes = [
    "include/",
  ],
  hdrs = glob([
    "include/boost/**/*.hpp",
  ]),
  srcs = [
  ],
  deps = [
    "@com_github_boost_type_traits//:type_traits",
    "@com_github_boost_core//:core",
    "@com_github_boost_config//:config",
  ]
)