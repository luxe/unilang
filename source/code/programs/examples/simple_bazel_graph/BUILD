sh_library(
    name = "a",
    srcs = ["a.sh"],
    data = [],
    deps = [],
)

sh_library(
    name = "b",
    srcs = ["b.sh"],
    data = [],
    deps = [],
)

sh_library(
    name = "c",
    srcs = ["c.sh"],
    data = [],
    deps = [
        ":a",
        ":b",
    ],
)

sh_library(
    name = "d",
    srcs = ["d.sh"],
    data = [],
    deps = [],
)

sh_library(
    name = "e",
    srcs = ["e.sh"],
    data = [],
    deps = [
        ":c",
        ":d",
    ],
)

sh_binary(
    name = "f",
    srcs = ["f.sh"],
    data = [],
    deps = [":e"],
)
