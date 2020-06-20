package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
        "src/libtess/priorityq-heap.c",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "src/**/*.c",
        "src/**/*.cc",
    ],
    exclude = [
        "src/libtess/priorityq-heap.c",
    ],
)

cc_library(
    name = "mesa_glu",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        "-DNDEBUG",
        "-DLIBRARYBUILD",
    ],
    includes = [
        ".",
        "include",
        "include/GL",
        "src",
        "src/include",
        "src/libnurbs/interface",
        "src/libnurbs/internals",
        "src/libnurbs/nurbtess",
    ],
    deps = [
    ],
)
