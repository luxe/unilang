
package(default_visibility = ["//visibility:public"])

cc_library(
  name = "libmagic",
  defines = ["HAVE_CONFIG_H"],
  linkopts = [],
  srcs = glob(["src/**/*.c",]),
  hdrs = glob(["src/**/*.h",]) + ["config.h"],
  deps = [],
  includes = [".","src"],
)