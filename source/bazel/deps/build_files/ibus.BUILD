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
        "src/tests/**",

        #main programs
        "bus/test-matchrule.c",
        "src/unicode-parser.c",
        "src/emoji-parser.c",
        "bus/test-stress.c",
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
        '-DIBUS_DATA_DIR=\\"FOO\\"',
        '-DX11_DATADIR=\\"FOO\\"',
        '-DIBUS_CACHE_DIR=\\"FOO\\"',
        '-DISOCODES_PREFIX=\\"/usr\\"',
        '-DX11_DATA_PREFIX=\\"/share/X11/locale\\"',
        '-DHAVE_CONFIG_H',
    ],
    includes = [
        ".",
        "bus",
        "ibus",
        "src",
    ],
    deps = [
        "@dbus",
        "@glib",
        "@libevent",
    ],
)
