package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "@nlohmann_json",
    ],
)
