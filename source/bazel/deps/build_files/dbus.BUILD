package(default_visibility = ["//visibility:public"])

#glob the files we care about
dbus_hdrs = glob(
    include = [
        "dbus/**/*.h",
        "bus/**/*.h",
    ],
    exclude = [
        "dbus/dbus-sysdeps-win.h",
    ],
)

dbus_srcs = glob(
    include = [
        "dbus/**/*.c",
        "bus/**/*.c",
    ],
    exclude = [
        "dbus/dbus-sysdeps-thread-win.c",
        "dbus/dbus-spawn-win.c",
        "dbus/dbus-transport-win.c",
        "dbus/dbus-file-win.c",
        "dbus/dbus-pipe-win.c",
        "dbus/dbus-sysdeps-wince-glue.c",
        "dbus/dbus-sysdeps-win.c",
        "dbus/dbus-sysdeps-util-win.c",

        #can't find system headers
        "bus/dir-watch-kqueue.c",
        "dbus/dbus-sysdeps-unix.c",

        #multiple defs
        "bus/config-parser-trivial.c",
        "bus/dir-watch-kqueue.c",
        "bus/dir-watch-inotify.c",
        "dbus/dbus-server-win.c",

        #main funcs
        "bus/main.c",
    ],
)

cc_library(
    name = "dbus_hdrs",
    hdrs = dbus_hdrs,
    includes = [
        ".",
        "bus",
        "dbus",
        "dbus/bus",
        "dbus/dbus",
    ],
)

cc_library(
    name = "dbus",
    srcs = dbus_srcs,
    includes = [
        ".",
        "bus",
        "dbus",
        "dbus/bus",
        "dbus/dbus",
    ],
    deps = [":dbus_hdrs"],
)
