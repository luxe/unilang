# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh



package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "hdr/**/*.h",
        "hdr/**/*.hpp",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
    ],
    exclude = [
    ],
)

cc_library(
    name = "lib",
    hdrs = hdrs,
    srcs = srcs,
    copts = ["-Wno-everything"],
    includes = [".","hdr"],
    deps = ["@sqlite3//:sqlite3"],
)

