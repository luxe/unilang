
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "corange",
    hdrs = glob([
        "include/**/*.h",
        "include/**/*.hpp",
    ]),
    includes = ["include"],
    srcs = glob([
        "src/**/*.c",
        "src/**/*.cpp",
        
    ]),
    deps = ["@SDL2//:SDL2","@opengl//:opengl"],
)
