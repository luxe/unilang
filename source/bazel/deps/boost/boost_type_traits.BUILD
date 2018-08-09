package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "type_traits",
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
  ]
)