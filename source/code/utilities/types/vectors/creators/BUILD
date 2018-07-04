package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
"//code/utilities/streams/filestreams/read_all:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/types/strings/observers/splitting:lib"
]
)
