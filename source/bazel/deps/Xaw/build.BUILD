package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

cc_library(
    name = "Xaw_headers",
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        ".",
    ],
    deps = [
    ],
)

srcs = glob(
    include = [
        "src/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "Xaw",
    srcs = srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
        "include",
        "src",
    ],
    deps = [
        ":Xaw_headers",
        "@Xmu//:Xmu_headers",
        #"@libXpm",
        "@xorg_libXt",
        "@xorg_libSM",
        "@xorg_libXext//:Xorg_libXext_headers",
        "@libXpm//:libXpm_headers",
        "@x11//:x11_hdrs",
    ],
)
