package(default_visibility = ["//visibility:public"])

cc_library(
    name = "pthreadpool",
    srcs = [
        "src/threadpool-pthreads.c",
    ],
    hdrs = [
        "include/pthreadpool.h",
    ],
    copts = [
        "-pthread",
        "-DFXDIV_USE_INLINE_ASSEMBLY=0",
        "-DTH_BLAS_MKL",
        "-D_GNU_SOURCE=1",
    ],
    includes = [
        "include/",
    ],
    deps = [
        "@fx_div//:fx_div",
    ],
    linkstatic = True,
)