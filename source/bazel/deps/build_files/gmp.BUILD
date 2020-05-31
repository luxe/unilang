package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
        "mini-gmp/**/*.h",
        "**/*.h",
        "mpn/**/*.h",
        "config.h",
        "mini-gmp/mini-gmp.c",
        "bootstrap.c",
        "gmp-impl.h",
        "gmp.h",
        "gmp-impl.h",
        "gmp-mparam.h",
        "gmpxx.h",
    ],
    exclude = [
    ],
)

cc_library(
    name = "gmp_headers",
    hdrs = hdrs,
    copts = [
    ],
    deps = [
    ],
)

srcs = glob(
    include = [
        #"bootstrap.c",
        "mpf/*.c",
        #"mpn/*.c",
        "mpq/*.c",
        "mpz/*.c",
        "mini-gmp/*.c",
    ],
    exclude = [
        "tal-notreent.c",
        "tal-debug.c",
    ],
)

cc_library(
    name = "gmp",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
        "-I$(GENDIR)",
    ],
    includes = [
        "include",
        "src",
        "mpn",
        "mini-gmp",
    ],
    deps = [
        ":gmp_headers",
    ],
)