package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "compat/**/*.h",
        "include/**/*.h",
        "*.h",
        "arc4random.c",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "compat/**/*.c",
        "*.c",
    ],
    exclude = [

        #Windows related:
        "libevent/buffer_iocp.c",
        "buffer_iocp.c",
        "evthread_win32.c",
        "bufferevent_async.c",
        "wepoll.c",
        "event_iocp.c",
    ],
)

cc_library(
    name = "libevent",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        ".",
        "include/",
        "libevent",
    ],
    #include_prefix = "sys",
    deps = [
    ],
)
