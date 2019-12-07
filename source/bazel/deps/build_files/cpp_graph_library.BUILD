package(default_visibility = ["//visibility:public"])

cc_library(
    name = "lib",
    hdrs = ["Graph.h","Node.h"],
    srcs = ["Graph.cpp","Node.cpp"]
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":lib"]
)