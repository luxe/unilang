package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(name = "printf_specifier")

hcp(
    name = "printf_specifier_settings",
    deps = [
        "//code/tools/transcompilers/unilang/type_converters/type-to-printf-specifier/settings:individual_printf_specifier_getter",
        "//code/tools/transcompilers/unilang/type_converters/type-to-printf-specifier/settings:printf_specifier",
    ],
)

hcp(
    name = "individual_printf_specifier_getter",
    deps = [
        "//code/tools/transcompilers/unilang/type_converters/type-to-printf-specifier/settings:printf_specifier",
    ],
)
