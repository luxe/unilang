package(default_visibility = ["//visibility:public"])

cc_library(
    name = "main",
    srcs = glob(
        ["googletest/src/*.cc","googletest/src/*.h",],
        exclude = ["googletest/src/gtest-all.cc"]
    ),
    hdrs = glob([
        "googletest/src/*.h",
        "googletest/include/**/*.h",
        "googletest/src/*.h"
    ]),
    includes = [
    "googletest/include",
    "googletest",
    "googletest/src",
    "googletest/include/gtest"],
    
    # copts = [
    # "-Iexternal/gtest/googletest/include",
    # "-Iexternal/gtest/googletest/include/gtest"],
    
    linkopts = ["-pthread"],
    visibility = ["//visibility:public"],
)
