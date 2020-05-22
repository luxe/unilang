package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    copts = ["--std=c++14"],
    deps = [
        "//code/utilities/filesystem/files/observers/lstat_wrap:lib",
        "//code/utilities/program/call:lib",
        "//code/utilities/streams/filestreams/read_all:lib",
        "//code/utilities/types/strings/observers/converting:lib",
        "//code/utilities/types/strings/observers/front_back:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/vectors/transformers:lib",
    ],
)
