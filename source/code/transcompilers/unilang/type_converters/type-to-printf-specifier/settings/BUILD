package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "printf_specifier")

hcp(name = "printf_specifier_settings", deps = [
"//code/transcompilers/unilang/type_converters/type-to-printf-specifier/settings:printf_specifier",
"//code/transcompilers/unilang/type_converters/type-to-printf-specifier/settings:individual_printf_specifier_getter",
])

hcp(name = "individual_printf_specifier_getter", deps = [
"//code/transcompilers/unilang/type_converters/type-to-printf-specifier/settings:printf_specifier",
])