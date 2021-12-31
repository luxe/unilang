py_test(
    name = "block_network_test",
    srcs = ["block_network_test.py"],
    # this should provide remote network isolation
    exec_properties = {
        "block-network": "true",
        "linux-sandbox": "true",
    },
    # This provides local network isolation
    #tags = ["block-network"],
)