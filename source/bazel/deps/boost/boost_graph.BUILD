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
    "@boost//:property_map",
    "@boost//:property_tree",
    "@boost//:lexical_cast",
    "@boost//:xpressive",
  ]
)