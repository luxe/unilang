package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
    ],
)
