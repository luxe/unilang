

sh_library(
    name = "a",
    srcs = ["a.sh"],
    deps = [],
    data = [],
)

sh_library(
    name = "b",
    srcs = ["b.sh"],
    deps = [],
    data = [],
)

sh_library(
    name = "c",
    srcs = ["c.sh"],
    deps = [":a",":b"],
    data = [],
)

sh_library(
    name = "d",
    srcs = ["d.sh"],
    deps = [],
    data = [],
)

sh_library(
    name = "e",
    srcs = ["e.sh"],
    deps = [":c",":d"],
    data = [],
)

sh_binary(
    name = "f",
    srcs = ["f.sh"],
    deps = [":e"],
    data = [],
)