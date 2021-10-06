# Description: a lightweight SQL database

licenses(["unencumbered"])  # Public domain.

cc_library(
    name = "sqlite3",
    srcs = ["sqlite3.c"],
    hdrs = [
        "sqlite3.h",
        "sqlite3ext.h",
    ],
    copts = ["-Wno-everything"],
    includes = ["."],
    linkopts = [
        "-pthread",
        "-ldl",
    ],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "sqlite3-shell",
    srcs = ["shell.c"],
    copts = ["-Wno-everything"],
    deps = [":sqlite3"],
)
