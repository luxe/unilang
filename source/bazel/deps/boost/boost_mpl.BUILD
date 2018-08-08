package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "mpl",
  includes = [
    "include/",
  ],
  hdrs = glob([
    "include/boost/**/*.hpp",
  ]),
  deps = [
    "@com_github_boost_preprocessor//:preprocessor",
    "@com_github_boost_type_traits//:type_traits",
  ],
)