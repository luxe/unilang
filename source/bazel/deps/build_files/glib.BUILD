package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "glib/**/*.h",
        "pcre/**/*.h",
        "gio/**/*.h",
        "gobject/**/*.h",
        "gmodule/**/*.h",
        "gio/strinfo.c",
    ],
    exclude = [
        "glib/dirent/dirent.h",
        "glib/dirent/dirent.c",
        
        #windows related:
        "gio/win32/gwinhttpvfs.h",
    ],
)

srcs = glob(
    include = [
        "glib/**/*.c",
        "pcre/**/*.c",
        "gio/**/*.c",
        "gobject/**/*.c",
        "gmodule/**/*.c",
    ],
    exclude = [
        
        #windows related:
        "glib/win_iconv.c",
        "glib/gwin32.c",
        "glib/gthread-win32.c",
        "gio/gregistrysettingsbackend.c",
        "gio/win32/**",
        "gio/gwin32volumemonitor.c",
        "gio/gwin32mount.c",
        
        #other:
        "glib/dirent/dirent.c",
        "glib/gnulib/signbitl.c",
        "glib/libcharset/localcharset.c",
        "glib/gnulib/signbitd.c",
        "glib/dirent/wdirent.c",
        "glib/gnulib/signbitf.c",
        "glib/gwin32.c",
        "glib/gthread-win32.c",
        "glib/gnulib/printf-frexp.c",
        "glib/gnulib/**",
        "gio/fam/gfamfilemonitor.c",
        "gio/tests/**",
        "gobject/tests/**",
        "gio/kqueue/gkqueuefilemonitor.c",
        #"glib/deprecated/gallocator.c"
    ],
)

cc_library(
    name = "glib",
    srcs = srcs,
    hdrs = hdrs,
    includes = [
        "glib",
        ".",
        "glib/dirent",
        "gobject",
        "gmodule",
        "glib/gio",
        "gio",
        "gio/fam"
    ],
    copts = [
    #'-DG_LOG_DOMAIN="GLib-GRegex"',
    '-DHAVE_MEMMOVE',
    '-DSUPPORT_UCP',
    '-DSUPPORT_UTF',
    '-DSUPPORT_UTF8',
    '-DNEWLINE=-1',
    '-DMATCH_LIMIT=10000000',
    '-DMATCH_LIMIT_RECURSION=8192',
    '-DMAX_NAME_SIZE=32',
    '-DMAX_NAME_COUNT=10000',
    '-DMAX_DUPLENGTH=30000',
    '-DLINK_SIZE=2',
    '-DPOSIX_MALLOC_THRESHOLD=10',
    '-DPCRE_STATIC',
    '-UBSR_ANYCRLF',
    '-UEBCDIC',
    '-DGLIB_COMPILATION',
],
)