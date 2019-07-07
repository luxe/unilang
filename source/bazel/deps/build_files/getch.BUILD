#cc_library(
#    name = "getch",
#    srcs = glob(["getch/src/**/*.c"]),
#    hdrs = glob(["getch/include/*.h"]),
#    includes = ["getch/include"],
#    visibility = ["//visibility:public"],
#)

cc_library(
    name = "getch_headers",
    hdrs = glob(["getch/include/*.h"]),
)

cc_library(
    name = "ch",
    srcs = glob(["getch/src/ch/**/*.c"]),
    includes = ["getch/include"],
    deps = [":getch_headers"],
    visibility = ["//visibility:public"],
)
