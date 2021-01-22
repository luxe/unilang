package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "src/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "src/**/*.c",
    ],
    exclude = [
        "src/gen-w32-lock-obj.c",
        "src/mkw32errmap.c",
        "src/w32-reg.c",
        "src/w32-lock.c",
        "src/w32-estream.c",
        "src/w32-iconv.c",
        "src/w32-thread.c",
        "src/w32-gettext.c",
        "src/spawn-w32.c",
        
        #programs
        "src/gpg-error.c",
        "src/mkheader.c",
        "src/mkw32errmap.c",
        "src/gen-posix-lock-obj.c",
        "src/gen-w32-lock-obj.c",
        "src/b64enc.c",
        "src/mkerrcodes.c",
    ],
)

cc_library(
    name = "libgpgerror",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        "-DHAVE_CONFIG_H",
        "-DLOCALEDIR=\\\"FOO\\\"",
        "-DPKGDATADIR=\\\"FOO\\\"",
    ],
    includes = [
        "src",
    ],
    deps = [
    ],
)
