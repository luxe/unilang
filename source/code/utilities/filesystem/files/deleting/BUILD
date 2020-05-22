package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)
