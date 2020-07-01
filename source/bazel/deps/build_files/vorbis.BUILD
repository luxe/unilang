package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "include/**/*.h",
        "lib/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "lib/**/*.c",
    ],
    exclude = [
        "lib/psytune.c",
        #"lib/sharedbook.c",
        "lib/barkmel.c",
    ],
)

cc_library(
    name = "vorbis",
    srcs = srcs,
    hdrs = hdrs,
    includes = [
        "include",
        "lib",
    ],
    deps = ["@ogg"],
)
