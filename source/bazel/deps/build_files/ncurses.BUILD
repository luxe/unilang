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
    #"-DUSE_WIDEC_SUPPORT",
    "-DHAVE_MBTOWC",
    "-DHAVE_MBLEN",
    "-DCHTYPE=char",
    "-DUSE_TERM_DRIVER",
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
        "ncurses/names.c",
        "ncurses/tinfo/doalloc.c",
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
        "ncurses/base/lib_slkrefr.c",
        "ncurses/widechar/**/*.c",
        
        "ncurses/base/lib_screen.c",
        "ncurses/base/sigaction.c",
        
        #main programs
        "c++/cursesmain.cc",
        "ncurses/tinfo/make_keys.c",
        "ncurses/tinfo/make_hash.c",
        "ncurses/tinfo/captoinfo.c",
        "ncurses/link_test.c",
        "ncurses/tty/lib_mvcur.c",
        "ncurses/tty/hardscroll.c",
        "ncurses/tty/hashmap.c",
        "ncurses/report_offsets.c",
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
