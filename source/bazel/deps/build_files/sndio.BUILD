package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "bsd-compat/**/*.h",
        "aucat/**/*.h",
        "sndiod/**/*.h",
        "libsndio/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "bsd-compat/**/*.c",
        #"aucat/**/*.c",
        "sndiod/**/*.c",
        "sndioctl/**/*.c",
        "libsndio/**/*.c",
        "midicat/**/*.c",
    ],
    exclude = [
        "aucat/aucat.c",
        "sndiod/sndiod.c",
        "sndioctl/sndioctl.c",
        "midicat/midicat.c",
    ],
)

cc_library(
    name = "sndio",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        "-D_GNU_SOURCE",
        "-DHAVE_SOCK_CLOEXEC",
        "-DHAVE_CLOCK_GETTIME",
        "-DUSE_ALSA",
        '-DSNDIO_USER=\\\"sndiod\\\"',
        "-DADATA_BITS=16",
    ],
    includes = [
        ".",
        "aucat",
        "bsd-compat",
        "libsndio",
        "sndiod",
    ],
    deps = [
        "@debian_stretch_amd64_sysroot//:alsa",
        "@debian_stretch_amd64_sysroot//:pulse_audio",
    ],
)
