package(default_visibility = ["//visibility:public"])

cc_library(
    name = "crossguid",
    srcs = glob([
        "src/**/*.cpp",
    ]),
    hdrs = glob([
        "include/**/*.h",
        "include/**/*.hpp",
    ]),
    copts = ["-DGUID_LIBUUID"],
    includes = ["include"],
    #linkopts = ["-luuid"],
    deps = ["@utilsLinux//:uuid"]
)
