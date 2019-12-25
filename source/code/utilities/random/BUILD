package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
        "//code/utilities/gmp:lib",
        "//code/utilities/types/char:lib",
        "//code/utilities/types/char:optional_letter_case",
        "@crossguid//:crossguid"
    ]
)
