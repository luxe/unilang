package(default_visibility = ["//visibility:public"])

cc_library(
    name = "headers",
    hdrs = [
            "src/config.h",
            "src/xinput.h",
    ],
    includes = [".","src/"],
)

cc_library(
    name = "lib",
    srcs = glob(["src/**/*.c"],exclude = ["src/xinput.c"]),
    linkopts = ["-lX11", "-lXext", "-lXi", "-lXrandr", "-lXinerama"],
    includes = [".","src/"],
    deps = [":headers"],
    copts = [
        "-DHAVE_CONFIG_H",
    ],
)

cc_binary(
    name = "xinput",
    srcs = ["src/xinput.c"],
    includes = [".","src/"],
    deps = [":lib"],
    copts = [
        "-DHAVE_CONFIG_H",
    ],
)