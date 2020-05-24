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
    ],
)

cc_library(
    name = "dbus_hdrs",
    hdrs = dbus_hdrs,
    includes = [
        "dbus",
        "dbus/dbus",
        "dbus/bus",
        "bus",
        ".",
    ],
)

cc_library(
    name = "dbus",
    srcs = dbus_srcs,
    includes = [
        "dbus",
        "dbus/dbus",
        "dbus/bus",
        "bus",
        ".",
    ],
    deps = [":dbus_hdrs"],
)
