package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = ["//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/types/strings/transformers/casing:lib",
    "@boost//:algorithm",
    ]
)
