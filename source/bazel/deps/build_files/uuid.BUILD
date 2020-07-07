package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "uuid/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "uuid/**/*.c",
    ],
    exclude = [
        "uuid/gen_uuid_nt.c",
    ],
)

cc_library(
    name = "uuid",
    srcs = srcs,
    hdrs = hdrs,
    copts = ["-fdeclspec"],
    includes = [
        ".",
        "uuid",
    ],
    deps = [],
)
