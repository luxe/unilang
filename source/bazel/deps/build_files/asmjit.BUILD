package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "asmjit",
    hdrs = glob([
        "src/asmjit/x86/*.h",
        "src/asmjit/base/*.h",
        "src/asmjit/*.h",
        "src/asmjit/core/*.h",
    ]),
    srcs = glob([
        "src/asmjit/base/*.cpp",
        "src/asmjit/x86/*.cpp",
        "src/asmjit/core/*.cpp",
    ]),
    copts = [
        "-DASMJIT_STATIC",
        "-fno-tree-vectorize",
        "-fmerge-all-constants",
        "-DTH_BLAS_MKL",
    ],
    linkopts = [
        "-lrt"
    ],
    includes = [
        "asmjit/",
        "src/",
    ],
    linkstatic = True,
)
