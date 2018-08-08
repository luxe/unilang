package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "smart_ptr",
  includes = [
    "include/",
  ],
  hdrs = glob([
    "include/boost/**/*.hpp",
  ]),
  srcs = [
  ],
  deps = [
    "@com_github_boost_predef//:predef",
    "@com_github_boost_throw_exception//:throw_exception",
  ]
)