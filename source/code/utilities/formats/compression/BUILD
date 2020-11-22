package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/utilities/program/call:lib",
        "//code/utilities/types/strings/observers/columns:lib",
        "//code/utilities/filesystem/files/temp:existing_temp_file",
        "//code/utilities/random/files:random_files",
        "//code/utilities/filesystem/files/moving:lib",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/types/strings/observers/path:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/filesystem/files/getting:lib",
    ],
)
