package(default_visibility = ["//visibility:public"])

cc_library(
    name = "php_random",
    srcs =  glob(["ext/standard/mt_rand.c",
            "ext/standard/random.c",
            "ext/standard/basic_functions.c",
            "ext/standard/lcg.c",
            #"Zend/*.c",
            #"Zend/Optimizer/*.c",
],

        exclude = [
            "Zend/Optimizer/ssa_integrity.c",
        ],
    ),

    hdrs = glob([
        "ext/standard/*h",
        "ext/standard/streams/*h",
        "ext/session/*.h",
        "main/*.h",
        "main/streams/*.h",
        "Zend/*.h",
        "TSRM/*.h",
        "ext/hash/*.h",
        "Zend/Optimizer/*.h",
    ]),
    copts = [],
    includes = [
        ".",
        "Zend",
        "ext/standard",
        "ext/session",
        "ext/standard/streams",
        "main",
        "main/streams",
        "TSRM",
    ],
    deps = [],
)
