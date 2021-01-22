package(
    default_visibility = ["//visibility:public"],
)
load("//bazel/rules/hcp:hcp.bzl", "hcp")

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "@boost//:tokenizer",
    ],
)

hcp(
    name = "words_deriver",
    deps = [
        "//code/utilities/types/strings/observers/char:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)