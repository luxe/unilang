package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "@com_github_boost_program_options//:program_options",
    ],
    linkopts = ["-lboost_program_options"],
)
