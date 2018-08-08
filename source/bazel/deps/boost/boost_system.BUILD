package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "system",
  includes = [
    "include/",
  ],
  hdrs = glob([
    "include/boost/**/*.h",
    "include/boost/**/*.hpp",
    "include/boost/**/*.ipp",
  ]),
  srcs = glob([
  	"src/*.cpp"
  ]),
  deps = [
    "@com_github_boost_assert//:assert",
    "@com_github_boost_config//:config",
    "@com_github_boost_core//:core",
    "@com_github_boost_predef//:predef",
  ]
)
