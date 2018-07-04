package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
"//code/utilities/shell:lib",
"//code/utilities/filesystem/files/observers/lstat_wrap:lib",
],
linkopts = ["-lboost_system", "-lboost_filesystem"]
)
