package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
"//code/utilities/shell:lib",
"//code/utilities/filesystem/files/getting:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/files/observers/lstat_wrap:lib",
"//code/utilities/filesystem/files/deleting:lib",
"//code/utilities/filesystem/files/observers/other:lib",
"//code/utilities/filesystem/files/creating:lib",
"//code/utilities/types/strings/transformers/removing:lib"
]
)
