package(default_visibility = ["//visibility:public"])

licenses(["notice"])

ncurses_copts = [
    "-Iexternal/ncurses",
    "-Iexternal/ncurses/include",
    "-Iexternal/ncurses/ncurses",
    #"-DUSE_TERMLIB",
    "-D_DEFAULT_SOURCE",
    "-D_XOPEN_SOURCE=600",
    "-DNCURSES_WIDECHAR",
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
        "include/capdefaults.c",
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
        "ncurses/**/*.c",
    ],
    exclude = [
        "include/capdefaults.c",
        "ncurses/win32con/**/*.c",
    ],
)

cc_library(
    name = "ncurses",
    hdrs = hdrs,
    srcs = srcs,
    copts = ncurses_copts,
    includes = [
        ".",
        "include",
        "include/ncurses",
    ],
    deps = [
    ],
)
