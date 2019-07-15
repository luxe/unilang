#
# ncurses (new curses) is a free software emulation of curses and more. It's essentially a library that provides an API to write text-based terminal user interfaces.
# This build file only compiles libtinfo, a low-level library that support the terminfo database and interfaces for ncurses
#
# References:
#  https://www.gnu.org/software/ncurses/
#  https://github.com/mirror/ncurses/tree/master/ncurses/tinfo
#

licenses(["notice"])  # MIT

#
# ncurses compiler options and defines
#
tinfo_copts = [
    "-Iexternal/ncurses",
    "-Iexternal/ncurses/include",
    "-Iexternal/ncurses/ncurses",
    "-D_DEFAULT_SOURCE",
    "-DUSE_TERMLIB",
    "-Wno-everything",
]

#
# libtinfo
#
cc_library(
    name = "tinfo",
    srcs =
        [
            "ncurses/base/define_key.c",
            "ncurses/base/key_defined.c",
            "ncurses/base/keybound.c",
            "ncurses/base/keyok.c",
            "ncurses/base/tries.c",
            "ncurses/base/version.c",
            "ncurses/codes.c",
            "ncurses/comp_captab.c",
            "ncurses/fallback.c",
            "ncurses/lib_keyname.c",
            "ncurses/names.c",
            "ncurses/tinfo/access.c",
            "ncurses/tinfo/add_tries.c",
            "ncurses/tinfo/alloc_entry.c",
            "ncurses/tinfo/alloc_ttype.c",
            "ncurses/tinfo/captoinfo.c",
            "ncurses/tinfo/comp_error.c",
            "ncurses/tinfo/comp_expand.c",
            "ncurses/tinfo/comp_hash.c",
            "ncurses/tinfo/comp_parse.c",
            "ncurses/tinfo/comp_scan.c",
            "ncurses/tinfo/db_iterator.c",
            "ncurses/tinfo/doalloc.c",
            "ncurses/tinfo/entries.c",
            "ncurses/tinfo/free_ttype.c",
            "ncurses/tinfo/getenv_num.c",
            "ncurses/tinfo/hashed_db.c",
            "ncurses/tinfo/home_terminfo.c",
            "ncurses/tinfo/init_keytry.c",
            "ncurses/tinfo/lib_acs.c",
            "ncurses/tinfo/lib_baudrate.c",
            "ncurses/tinfo/lib_cur_term.c",
            "ncurses/tinfo/lib_data.c",
            "ncurses/tinfo/lib_has_cap.c",
            "ncurses/tinfo/lib_kernel.c",
            "ncurses/tinfo/lib_longname.c",
            "ncurses/tinfo/lib_napms.c",
            "ncurses/tinfo/lib_options.c",
            "ncurses/tinfo/lib_raw.c",
            "ncurses/tinfo/lib_setup.c",
            "ncurses/tinfo/lib_termcap.c",
            "ncurses/tinfo/lib_termname.c",
            "ncurses/tinfo/lib_tgoto.c",
            "ncurses/tinfo/lib_ti.c",
            "ncurses/tinfo/lib_tparm.c",
            "ncurses/tinfo/lib_tputs.c",
            "ncurses/tinfo/lib_ttyflags.c",
            "ncurses/tinfo/name_match.c",
            "ncurses/tinfo/obsolete.c",
            "ncurses/tinfo/parse_entry.c",
            "ncurses/tinfo/read_entry.c",
            "ncurses/tinfo/read_termcap.c",
            "ncurses/tinfo/strings.c",
            "ncurses/tinfo/trim_sgr0.c",
            "ncurses/tinfo/write_entry.c",
            "ncurses/trace/lib_trace.c",
            "ncurses/trace/visbuf.c",
            "ncurses/tty/lib_twait.c",
            "ncurses/unctrl.c",
        ],
    # Some *.c files are "#included" in this project
    hdrs = glob([
        "include/*.h",
        "include/*.c",
        "ncurses/*.h",
        "ncurses/*.c",
        "ncurses/tinfo/*.h",
        "ncurses/tinfo/*.c",
    ]),
    copts = tinfo_copts,
    visibility = ["//visibility:public"],
)
