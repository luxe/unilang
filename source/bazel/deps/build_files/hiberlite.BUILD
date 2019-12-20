
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hiberlite",
    hdrs = glob([
        "include/**/*.h",
        "include/**/*.hpp",
    ]),
    srcs = glob([
        "include/**/*.cpp",
    ]),
    includes = ["include"],
    deps = [
        "@sqlite3//:sqlite3",
    ],
    copts = [
        "-Wno-everything",
    ],
)   
