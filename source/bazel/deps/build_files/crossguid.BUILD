
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "crossguid",
    hdrs = glob([
        "include/**/*.h",
        "include/**/*.hpp",
    ]),
    includes = ["include"],
    srcs = glob([
        "src/**/*.cpp",
        
    ]),
    copts = ["-DGUID_LIBUUID"],
    linkopts = ["-luuid"]
)
