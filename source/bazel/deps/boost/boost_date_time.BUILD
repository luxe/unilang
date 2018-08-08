package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "date_time",
  includes = [
    "include/",
  ],
  hdrs = glob([
    "include/boost/**/*.h",
    "include/boost/**/*.hpp",
    "include/boost/**/*.ipp",
  ]),
    linkopts = ["-pthread", "-lrt"],
  srcs = glob([
    "src/*.cpp"
  ]),
  deps = [
    "@com_github_boost_mpl//:mpl",
    "@com_github_boost_smart_ptr//:smart_ptr",
    "@com_github_boost_utility//:utility",
  ]
)