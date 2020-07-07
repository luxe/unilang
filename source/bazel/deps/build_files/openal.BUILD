package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "include/**/*.h",
        "OpenAL32/Include/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "OpenAL32/**/*.c",
        "Alc/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "openal",
    #srcs = srcs,
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        "include",
        "include/AL",
        "OpenAL32/Include",
    ],
    deps = [
        "@system//:openal",
    ],
)
