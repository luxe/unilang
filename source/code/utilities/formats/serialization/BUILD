package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "boost",
    srcs = ["boost.cpp"],
    hdrs = ["boost.hpp"],
    deps = [
        "@boost//:serialization",
    ],
)

cc_library(
    name = "protobuf",
    srcs = ["protobuf.cpp"],
    hdrs = ["protobuf.hpp"],
    deps = [
        "//code/utilities/formats/json/functions:lib",
        "@com_google_protobuf//:protobuf",
    ],
)
