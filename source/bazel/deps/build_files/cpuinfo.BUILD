package(default_visibility = ["//visibility:public"])

cc_library(
    name = "local_clog_dep",
    srcs = [
        "deps/clog/src/clog.c",
    ],
    hdrs = glob([
        "deps/clog/include/*.h",
    ]),
    includes = [
        "deps/clog/include/",
    ],
    linkstatic = True,
)

cc_library(
    name = "cpuinfo",
    srcs = glob(
        [
            "src/*.c",
            "src/linux/*.c",
            "src/x86/*.c",
            "src/x86/cache/*.c",
            "src/x86/linux/*.c",
        ],
        exclude = [
            "src/linux/mockfile.c",
            "src/x86/mockcpuid.c",
        ],
    ),
    hdrs = glob([
        "include/*.h",
        "src/*.h",
        "src/cpuinfo/*.h",
        "src/include/*.h",
        "src/x86/*.h",
        "src/x86/linux/*.h",
        "src/linux/*.h",
    ]),
    copts = [
        "-DCPUINFO_LOG_LEVEL=2",
        "-DTH_BLAS_MKL",
        "-D_GNU_SOURCE=1",
    ],
    includes = [
        "src",
        "include",
    ],
    deps = [
        ":local_clog_dep",
    ],
    linkstatic = True,
)