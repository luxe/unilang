package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = ["//code/utilities/types/char:lib",
    "//code/utilities/types/wstrings/transformers/trimming:lib",
    "@boost//:algorithm",
    "@boost//:range",]
)
