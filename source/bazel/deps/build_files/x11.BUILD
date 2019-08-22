package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "x11",
    hdrs = glob([
        "include/X11/*.h",
    ]),
    srcs = glob([
        "src/**/*.h",
        "src/**/*.c",
    ]),
    copts = ["-DXLOCALELIBDIR=\\\"/usr/local/lib/X11/locale\\\""],
    includes = ["include/X11","src"],
    linkstatic = True,
    deps = ["@xkbcommon//:xkbcommon"],
)