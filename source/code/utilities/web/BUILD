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
    "//code/utilities/web:html_fetch_settings",
    "//code/utilities/web:web_json_extraction_settings",
    "//code/utilities/json/extraction:json_extractor",
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

hcp(name = "web_json_extraction_settings", deps = [
    "//code/utilities/web:html_fetch_settings",
    "//code/utilities/json/extraction:json_extraction_settings",
])