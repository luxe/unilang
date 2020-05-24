package(default_visibility = ["//visibility:public"])
#load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

# Common include paths
sdl_includes = [
    "include",
    "src/video/x11",
]

sdl_srcs = glob(
    include = [
        "src/**/*.c",
        "src/**/*.h",
    ],
    exclude = [
        "src/video/qnx/**",
        "src/haptic/windows/**",
        "src/test/*.c",
    ],
)

# just the headers
cc_library(
    name = "SDL2_includes",
    hdrs = glob(["include/**/*.h"]),
    includes = sdl_includes,
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SDL2",
    srcs = sdl_srcs,
    hdrs = glob(["include/**/*.h"]),
    linkopts = ["-lSDL2"],
    textual_hdrs = glob(["src/thread/generic/*.c"]),
    visibility = ["//visibility:public"],
    deps = [":SDL2_includes"],
)

# load("@rules_cc//cc:defs.bzl", "cc_library")

# alias(
#     name = "windows",
#     actual  = "@bazel_tools//src/conditions:windows"
# )

# alias(
#     name = "macos",
#     actual  = "@bazel_tools//src/conditions:darwin_x86_64"
# )

# alias(
#     name = "linux",
#     actual  = "@bazel_tools//src/conditions:linux_x86_64"
# )

# SDL_LINKOPTS = select({
#     "//:windows": [
#         "-DEFAULTLIB:user32",
#         "-DEFAULTLIB:gdi32",
#         "-DEFAULTLIB:winmm",
#         "-DEFAULTLIB:imm32",
#         "-DEFAULTLIB:ole32",
#         "-DEFAULTLIB:oleaut32",
#         "-DEFAULTLIB:version",
#         "-DEFAULTLIB:uuid",
#         "-DEFAULTLIB:shell32",
#         "-DEFAULTLIB:advapi32",
#         "-DEFAULTLIB:hid",
#         "-DEFAULTLIB:setupapi",
#         "-DEFAULTLIB:opengl32",
#         "-DEFAULTLIB:kernel32",
#     ],
#     "//conditions:default": [],
# })

cc_library(
    name = "SDL2_hdrs",
    hdrs = glob(["include/**/*.h"]),
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SDL2base",
    srcs = [
        "src/SDL.c",
        "src/SDL_assert.c",
        "src/SDL_dataqueue.c",
        "src/SDL_error.c",
        "src/SDL_hints.c",
        "src/SDL_log.c",
    ],
    hdrs = glob([
        "include/**/*.h",
        "src/*.h",
    ]),
    includes = [
        "include",
        "src",
    ],
    deps = ["//src/thread"],
)

# cc_library(
#     name = "SDL2internal",
#     hdrs = glob(["include/**/*.h", "src/*.h"]),
#     includes = ["include", "src"],
#     visibility = ["//:__subpackages__"],
# )

# apple_binary(
#     name = "SDL2_mac",
#     binary_type = "dylib",
#     deps = [
#         ":SDL2_lib",
#     ],
#     platform_type = "macos",
#     visibility = ["//:__subpackages__"],
# )

# genrule(
#     name = "SDL2_dylib",
#     srcs = ["SDL2_mac"],
#     outs = ["SDL2.dylib"],
#     cmd = "cp $(location SDL2_mac) $(location SDL2.dylib)",
# )

# cc_binary(
#     name = "libSDL2.so",
#     linkshared = True,
#     deps = [
#         ":SDL2_lib",
#     ],
#     visibility = ["//visibility:public"],
# )

# cc_binary(
#     name = "SDL2.dll",
#     linkshared = True,
#     deps = [
#         ":SDL2_lib",
#     ],
#     linkopts = SDL_LINKOPTS,
#     visibility = ["//visibility:public"],
# )

# cc_library(
#     name = "SDL2_lib",
#     hdrs = glob(["include/*.h"]),
#     includes = ["include", "src"],
#     srcs = glob(["include/*.h", "src/*.c", "src/*.h"]),
#     alwayslink = True,
#     deps = [
#         ":SDL2internal",
#         "//src/atomic:atomic",
#         "//src/audio:audio",
#         "//src/core:core",
#         "//src/cpuinfo:cpuinfo",
#         "//src/dynapi:dynapi",
#         "//src/events:events",
#         "//src/file:file",
#         "//src/filesystem:filesystem",
#         "//src/haptic:haptic",
#         "//src/hidapi:hidapi",
#         "//src/joystick:joystick",
#         "//src/libm:libm",
#         "//src/loadso:loadso",
#         "//src/locale:locale",
#         "//src/main:main",
#         "//src/power:power",
#         "//src/render:render",
#         "//src/sensor:sensor",
#         "//src/stdlib:stdlib",
#         "//src/thread:thread",
#         "//src/timer:timer",
#         "//src/video:video",
#     ],
#     visibility = ["//visibility:public"],
# )

# cc_library(
#     name = "SDL2test",
#     hdrs = glob(["include/SDL_test*.h"]),
#     srcs = glob(["src/test/**/*.c"]),
#     deps = ["//:SDL2"],
#     visibility = ["//test:__subpackages__"],
# )
