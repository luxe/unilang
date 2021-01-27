package(default_visibility = ["//visibility:public"])

cc_library(
    name = "lib",
    srcs = [
        "Graph.cpp",
        "Node.cpp",
    ],
    hdrs = [
        "Graph.h",
        "Node.h",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":lib"],
)
