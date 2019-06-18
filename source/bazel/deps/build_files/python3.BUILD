cc_library(
    name = "headers",
    hdrs = glob([
        "usr/include/python3.6m/**",
        "usr/include/x86_64-linux-gnu/python3.6m/**",
    ]),
    includes = [
        "usr/include/",
        "usr/include/python3.6m",
    ],
    visibility = ["//visibility:public"],
)

# Converts libpython3.6m-pic into a shared object. This is needed for embedded support of custom bindings.
cc_import(
    name = "libpython3.6m-pic",
    static_library = "usr/lib/python3.6/config-3.6m-x86_64-linux-gnu/libpython3.6m-pic.a",
    alwayslink = 1,
)

cc_binary(
    name = "libpython3.6m.so",
    copts = ["-fPIC"],
    linkopts = [
        "-ldl",
        "-lutil",
    ],
    linkshared = True,
    visibility = ["//visibility:public"],
    deps = [
        ":headers",
        ":libpython3.6m-pic",
        "@expat",
        "@net_zlib_zlib//:zlib",
    ],
)

genrule(
    name = "binding_libs",
    srcs = [":libpython3.6m.so"],
    outs = ["bindings/libpython3.6m.so"],
    cmd = "cp $< $@",
    visibility = ["//visibility:public"],
)

# Creates a filegroup of "everything" for use by our hermetic Python.
filegroup(
    name = "everything",
    srcs = glob(
        ["**"],
        exclude = ["**/* *"],
    ) + [":binding_libs"],
    visibility = ["//visibility:public"],
)

# Packages all of this into a single target, and adds in the Python3 runfiles as data dependencies.
cc_library(
    name = "python3",
    srcs = [":libpython3.6m.so"],
    data = glob([
        "usr/lib/python3.6/*.py",
        "usr/lib/python3.6/**/*.py",
    ]),
    visibility = ["//visibility:public"],
    deps = [":headers"],
)