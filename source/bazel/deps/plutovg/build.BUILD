package(default_visibility = ["//visibility:public"])

#3rd party lib needed.  Couldn't exactly tell where best to source it
#so used it has it was packaged
software_hdrs = glob(
    include = [
        "3rdparty/software/**/*.h",
    ],
    exclude = [
    ],
)

software_srcs = glob(
    include = [
        "3rdparty/software/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "software",
    srcs = software_srcs,
    hdrs = software_hdrs,
    copts = [
        "-Wno-everything",
    ],
    includes = ["include"],
    deps = [
        "@stb",
    ],
)

#the library itself
pluto_hdrs = glob(
    include = [
        "include/**/*.h",
        "source/**/*.h",
    ],
    exclude = [
    ],
)

pluto_srcs = glob(
    include = [
        "source/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "plutovg",
    srcs = pluto_srcs,
    hdrs = pluto_hdrs,
    copts = [
        "-Wno-everything",
    ],
    includes = [
        "3rdparty/software",
        "include",
    ],
    deps = [
        ":software",
        "@stb",
    ],
)

#example program
cc_binary(
    name = "example",
    srcs = ["example/smiley.c"],
    deps = ["@plutovg"],
)
