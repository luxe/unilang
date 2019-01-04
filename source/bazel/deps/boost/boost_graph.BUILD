package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "graph",
  includes = [
    "include/",
  ],
  hdrs = glob([
    "include/boost/**/*.hpp",
  ]),
  srcs = [
  ],
  deps = [
    "@com_github_boost_property_map//:property_map",
    "@boost//:property_tree",
    "@boost//:lexical_cast",
    "@boost//:xpressive",
  ]
)