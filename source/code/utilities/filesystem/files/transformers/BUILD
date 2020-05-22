package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/utilities/filesystem/files/getting:lib",
        "//code/utilities/output/printers:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/reverse:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)
