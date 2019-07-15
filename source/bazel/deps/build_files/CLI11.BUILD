# Build file for CLI11 for argument parsing

licenses(["notice"])  # BSD-3 Clause

#
# Glob all of the header files: CLI/*.hpp .
#
cc_library(
    name = "CLI11",
    hdrs = glob(["include/CLI/*.hpp"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
)
