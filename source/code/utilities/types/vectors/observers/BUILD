package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
copts = ["--std=c++14"],
    deps = [
"//code/utilities/types/strings/observers/char:lib",
"//code/utilities/types/general:lib",
]
)
