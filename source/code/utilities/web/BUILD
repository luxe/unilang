package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
    "//code/utilities/types/strings/observers/converting:lib",
    "//code/utilities/shell:lib",
    "@curl",
    "//code/utilities/web:html_fetch_settings"
    ]
)

enum_cpp(name = "html_fetch_strategy",
values = [
"curl_lib"
,"curl_command"
])

hcp(name = "html_fetch_settings", deps = [
    "//code/utilities/web:html_fetch_strategy",
])