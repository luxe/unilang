cc_library(
    name = "cpr",
    srcs = glob(["cpr/*.cpp"]),
    hdrs = glob(["include/cpr/*.h"]),
    copts = ["-Wno-everything"],
    includes = ["include"],
    visibility = ["//visibility:public"],
    deps = ["@curl"],
)
