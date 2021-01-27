package(default_visibility = ["//visibility:public"])

cc_library(
    name = "sqlite_orm",
    hdrs = glob([
        "include/**/*.h",
        "include/**/*.hpp",
    ]),
    includes = ["include"],
    deps = [
        "@sqlite3",
    ],
)
