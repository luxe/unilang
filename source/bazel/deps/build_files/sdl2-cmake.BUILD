package(default_visibility = ["//visibility:public"])
load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

#cmake_external(
#   name = "SDL2",
#   lib_source = "src",
#)

cc_library(
    name="SDL2_lib",
    hdrs = glob(["include/**/*.h"]),
    srcs = ["lib/x86/SDL2.lib"],
)

cc_library(
    name = "SDL2",
    hdrs = glob(["include/**/*.h"]),
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
    deps = [":SDL2_lib"]
)