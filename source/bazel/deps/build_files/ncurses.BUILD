package(default_visibility = ["//visibility:public"])
licenses(["notice"])

ncurses_copts = [
    "-Iexternal/ncurses",
    "-Iexternal/ncurses/include",
    "-Iexternal/ncurses/ncurses",
    "-D_DEFAULT_SOURCE",
    "-DUSE_TERMLIB",
    "-Wno-everything",
]

#glob the files we care about
hdrs = glob(
    include = [
        "include/**/*.h",
        "panel/**/*.h",
        "menu/**/*.h",
        "form/**/*.h",
        "c++/**/*.h",
        "ncurses/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "include/**/*.c",
        "panel/**/*.c",
        "menu/**/*.c",
        "form/**/*.c",
        "c++/**/*.c",
        "ncurses/**/*.cc",
    ],
    exclude = [
    ],
)

cc_library(
    name = "ncurses",
    srcs = srcs,
    hdrs = hdrs,
    copts = ncurses_copts,
    includes = [
        ".",
    ],
    deps = [
    ],
)