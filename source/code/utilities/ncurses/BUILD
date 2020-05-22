package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "scoped_ncurses",
    hdrs = ["scoped_ncurses.hpp"],
    linkopts = ["-lncurses"],
    deps = [],
)

cc_library(
    name = "scoped_getch",
    srcs = ["scoped_getch.cpp"],
    hdrs = ["scoped_getch.hpp"],
    deps = ["@getch"],
)
