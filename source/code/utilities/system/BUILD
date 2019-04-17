package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = ["//code/utilities/shell:lib"]
)

cc_binary(
  name = "env",
  srcs = ["env.cpp"],
  deps = ["//code/utilities/system:lib"]
)