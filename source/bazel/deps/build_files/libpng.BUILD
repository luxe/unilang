# Ref: https://github.com/googlecartographer/cartographer/blob/master/bazel/third_party/libpng.BUILD
# Description:
#   libpng is the official PNG reference library.

licenses(["notice"])  # BSD/MIT-like license

cc_library(
    name = "libpng",
    srcs = [
        "png.c",
        "pngerror.c",
        "pngget.c",
        "pngmem.c",
        "pngpread.c",
        "pngread.c",
        "pngrio.c",
        "pngrtran.c",
        "pngrutil.c",
        "pngset.c",
        "pngtrans.c",
        "pngwio.c",
        "pngwrite.c",
        "pngwtran.c",
        "pngwutil.c",
    ],
    hdrs = [
        "png.h",
        "pngconf.h",
        "pngdebug.h",
        "pnginfo.h",
        "pnglibconf.h",
        "pngpriv.h",
        "pngstruct.h",
    ],
    includes = ["."],
    #linkopts = ["-lm"],
    visibility = ["//visibility:public"],
    deps = ["@zlib_internal"],
)
