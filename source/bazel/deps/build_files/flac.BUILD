package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "include/**/*.h",
        "src/include/**/*.h",
        "src/libFLAC/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "src/libFLAC/**/*.c",
    ],
    exclude = [

        #Windows related
        "src/libFLAC/windows_unicode_filenames.c",
    ],
)

cc_library(
    name = "flac",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        '-DPACKAGE_VERSION=\\"1.3.3\\"',
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
        "include",
        "libFLAC",
        "libFLAC/include",
        "src",
        "src/libFLAC",
        "src/libFLAC/include",
        "src/libFLAC/include/private",
    ],
    deps = [
        "@ogg",
    ],
)
