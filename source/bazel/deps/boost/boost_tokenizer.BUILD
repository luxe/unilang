package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "tokenizer",
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
      "@com_github_boost_iterator//:iterator",
      "@com_github_boost_throw_exception//:throw_exception",
  ]
)
