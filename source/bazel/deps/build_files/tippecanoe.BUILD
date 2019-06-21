package(default_visibility = ["//visibility:public"])


#Notes: had to get rid of a japanese file (non-ascii error)

# Nested Folders
cc_library(
    name = "json_pull",
    hdrs = ["jsonpull/jsonpull.h"],
    srcs = ["jsonpull/jsonpull.c"],
)

cc_library(
    name = "milo",
    hdrs = ["milo/dtoa_milo.h"],
)

cc_library(
    name = "protozero",
    hdrs = glob(["protozero/**/*.hpp"]),
)

cc_library(
    name = "mapbox",
    hdrs = glob(["mapbox/**/*.hpp"]),
)


cc_library(
    name = "catch",
    hdrs = ["catch/catch.hpp"],
)

#Main Source Code
cc_library(
    name = "main_lib",
    hdrs = glob(["*.hpp"]),
    srcs = glob(["*.cpp"]),
    deps = [
        "@sqlite3//:sqlite3",
        ":json_pull",
        ":milo",
        ":protozero",
        ":catch",
        ":mapbox",
    ]
)