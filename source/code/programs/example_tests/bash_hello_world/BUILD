package(
    default_visibility = ["//visibility:public"],
)

sh_test(
    name = "main",
    srcs = ["main.sh"],
    exec_properties = {
        #"block-network": "true",
        #"linux-sandbox": "true",
        #"debug-before-execution": "true",
    },
    tags = [
        "block-network",
        "no-sandbox",
        "requires-network",
    ],
)
