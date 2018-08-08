package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "asio",
  includes = [
    "include/",
  ],
  hdrs = glob([
    "include/boost/**/*.h",
    "include/boost/**/*.hpp",
    "include/boost/**/*.ipp",
  ]),
  srcs = [
  ],
  deps = [
    "@com_github_boost_bind//:bind",
    "@com_github_boost_date_time//:date_time",
    "@com_github_boost_fusion//:fusion",
    "@com_github_boost_regex//:regex",
    "@com_github_boost_system//:system",
    "@com_github_boost_throw_exception//:throw_exception"
  ]
)
