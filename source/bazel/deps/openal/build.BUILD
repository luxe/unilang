package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "include/**/*.h",
        "OpenAL32/Include/**/*.h",
        "Alc/**/*.inc",
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
    # srcs = srcs,
    # hdrs = hdrs,
    copts = [
    ],
    includes = [
        "OpenAL32/Include",
        "include",
        "include/AL",
    ],
    deps = [
        # "@system//:asoundLib_hdr",
        # "@system//:alsa_hdrs",
        "@system//:openal",
        "@system//:openal_hdrs",
    ],
)
