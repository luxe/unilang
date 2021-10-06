package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "scoped_ncurses",
    hdrs = ["scoped_ncurses.hpp"],
    deps = ["@ncurses"],
)

cc_library(
    name = "scoped_getch",
    srcs = ["scoped_getch.cpp"],
    hdrs = ["scoped_getch.hpp"],
    deps = ["@getch"],
)
