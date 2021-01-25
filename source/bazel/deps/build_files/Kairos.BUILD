package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "Kairos/*.hpp",
        "Kairos/*.inl",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "Kairos/*.cpp",
    ],
    exclude = [
    ],
)

cc_library(
    name = "Kairos",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        ".",
        "Kairos",
    ],
    deps = [
    ],
)


#an example to test laggy-ness
cc_binary(
    name = "time_step_example",
    srcs = ["examples/timeStepExample.cpp"],
    deps = [
        ":Kairos",
        "@sfml",
        "@system//:GL",
    ]
)
cc_binary(
    name = "time_step_lite_example",
    srcs = ["examples/timestepLiteExample.cpp"],
    deps = [
        ":Kairos",
        "@sfml",
        "@system//:GL",
    ]
)