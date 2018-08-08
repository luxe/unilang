package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "random",
  includes = [
      "include/",
  ],
  hdrs = glob([
      "include/boost/**/*.hpp",
  ]),
  srcs = glob([
  	"src/*.cpp"
  ]),
  deps = [
      "@com_github_boost_config//:config",
      "@com_github_boost_core//:core",
      "@com_github_boost_integer//:integer",
      "@com_github_boost_system//:system",
      "@com_github_boost_throw_exception//:throw_exception",
  ]
)
