package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "bus/**/*.h",
        "ibus/**/*.h",
        "src/**/*.h",
        "config.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "bus/**/*.c",
        "ibus/**/*.c",
        "src/**/*.c",
    ],
    exclude = [
        "src/tests/**"
    ],
)

cc_library(
    name = "ibus",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        "-DIBUS_COMPILATION",
        '-DLIBEXECDIR=\\"FOO\\"',
        '-DBINDIR=\\"FOO\\"',
        '-DBUS_DATA_DIR=\\"FOO\\"',
        '-DX11_DATADIR=\\"FOO\\"',
    ],
    includes = [
        ".",
        "bus",
        "ibus",
        "src",
    ],
    deps = ["@glib","@dbus//:dbus"],
)
