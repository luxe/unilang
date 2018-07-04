package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    copts = ["--std=c++14"],
    deps = [
"//code/utilities/types/strings/observers/front_back:lib",
"//code/utilities/types/strings/observers/converting:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/vectors/converters:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/types/strings/observers/splitting:lib",
]
)
