# Ref: https://github.com/googlecartographer/cartographer/blob/master/bazel/third_party/pixman/pixman.BUILD
# Description:
#   pixman is a library that provides low-level pixel manipulation features.

licenses(["notice"])  # X11/MIT

COMMON_SRCS = [
    "pixman/pixman.c",
    "pixman/pixman-access.c",
    "pixman/pixman-access-accessors.c",
    "pixman/pixman-arm.c",
    "pixman/pixman-bits-image.c",
    "pixman/pixman-combine-float.c",
    "pixman/pixman-combine32.c",
    "pixman/pixman-conical-gradient.c",
    "pixman/pixman-edge-accessors.c",
    "pixman/pixman-edge.c",
    "pixman/pixman-fast-path.c",
    "pixman/pixman-filter.c",
    "pixman/pixman-general.c",
    "pixman/pixman-glyph.c",
    "pixman/pixman-gradient-walker.c",
    "pixman/pixman-image.c",
    "pixman/pixman-implementation.c",
    "pixman/pixman-linear-gradient.c",
    "pixman/pixman-matrix.c",
    "pixman/pixman-mips.c",
    "pixman/pixman-noop.c",
    "pixman/pixman-ppc.c",
    "pixman/pixman-radial-gradient.c",
    "pixman/pixman-region16.c",
    "pixman/pixman-region32.c",
    "pixman/pixman-solid-fill.c",
    "pixman/pixman-timer.c",
    "pixman/pixman-trap.c",
    "pixman/pixman-utils.c",
    "pixman/pixman-x86.c",
]

cc_library(
    name = "pixman",
    srcs = COMMON_SRCS + [
        "pixman/pixman-accessor.h",
        "pixman/pixman-combine32.h",
        "pixman/pixman-compiler.h",
        "pixman/pixman-edge-imp.h",
        "pixman/pixman-inlines.h",
        "pixman/pixman-private.h",
        "pixman/pixman-version.h",
        "pixman/pixman.h",
        "pixman/config.h",
    ],
    hdrs = [
        "pixman/pixman-access.c",
        "pixman/pixman-edge.c",
        "pixman/pixman-region.c",
    ],
    copts = [
        "-Wno-everything",
        "-DHAVE_CONFIG_H",
    ],
    includes = ["pixman"],
    visibility = ["//visibility:public"],
)
