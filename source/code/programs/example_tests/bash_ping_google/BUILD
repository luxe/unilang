package(
    default_visibility = ["//visibility:public"],
)

sh_test(
    name = "main",
    srcs = ["main.sh"],
    #tags = ["block-network"],
    exec_properties = {
        "block-network": "true",
        "debug-before-execution": "true",
    },
)
