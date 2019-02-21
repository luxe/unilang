package(default_visibility = ["//visibility:public"])
load("@rules_foreign_cc//tools/build_defs:cmake.bzl", "cmake_external")

#cmake_external(
#   name = "SDL2",
#   lib_source = "src",
#)

cc_import(
    name="main_lib",
    #hdrs = glob(["include/**/*.h"]),
    #srcs = ["lib/x64/SDL2.dll"],
    shared_library = "lib/x64/SDL2.lib",
    visibility = ["//visibility:public"],
)

cc_library(
    name="other_lib",
    #srcs = ["lib/x84/SDL2.lib"],
    visibility = ["//visibility:public"],
)

cc_library(
    name="all_lib",
    visibility = ["//visibility:public"],
    deps = [":main_lib", ":other_lib"]
)

cc_library(
    name="all_test",
    visibility = ["//visibility:public"],
    srcs= ["@SDL2//:lib/x84/SDL2.lib", "@SDL2//:lib/x84/SDL2main.lib"]
)

cc_library(
    name = "SDL2",
    hdrs = glob(["include/**/*.h"]),
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
    #deps = [":main_lib"]
)