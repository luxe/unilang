package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "search_engine_url_devise_settings", deps = [
    "//code/utilities/web/google:google_search_url_devise_settings",
    "//code/utilities/web/google:google_json_url_devise_settings",
    "//code/utilities/web/bing:bing_json_url_devise_settings",
])

hcp(name = "search_engine_url_deviser", deps = [
    "//code/utilities/web/search_engines:search_engine_url_devise_settings",
    "//code/utilities/web/search_engines:search_engine_fetch_settings",
])

hcp(name = "search_engine_fetch_settings", deps = [
    "//code/utilities/web:html_fetch_settings",
])