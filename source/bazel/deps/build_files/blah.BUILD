package(default_visibility = ["//visibility:public"])

#build headers
hdrs = glob(
    include = [
        "include/**/*.h",
        "include/**/*.hpp",
        "src/**/*.hpp",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

cc_library(
    name = "hdrs",
    hdrs = hdrs,
    includes = [
        "include",
    ],
)


cc_library(
    name = "blah",
    srcs = glob(["src/**/*.cpp"]),
    includes = [
    ],
    copts = [
        "-DOPENGL_ENABLED",
        "-DSDL2_ENABLED",
        "-DBLAH_USE_SDL2",
    ],
    deps = [
    ":hdrs",
        "@system//:SDL2_hdrs",
        "@system//:SDL2",
    ],
)
















# srcs = glob(
#     include = [
#         "src/**/*.cpp",
#         "src/**/*.c",
#         "src/**/*.hpp",
#         "src/**/*.h",
#     ],
#     exclude = [
#     ],
# )

# cc_library(
#     name = "blah",
#     srcs = srcs,
#     includes = [
#         ".",
#         "include",
#         "include/blah",
#         "include/blah/containers",
#         "include/blah/core",
#         "include/blah/drawing",
#         "include/blah/graphics",
#         "include/blah/images",
#         "include/blah/input",
#         "include/blah/math",
#         "include/blah/streams",
#         "src",
#         "src/containers",
#         "src/core",
#         "src/drawing",
#         "src/graphics",
#         "src/images",
#         "src/input",
#         "src/internal",
#         "src/math",
#         "src/streams",
#         "src/third_party",
#     ],
#     deps = [
#         ":hdrs",
#     ],
# )
