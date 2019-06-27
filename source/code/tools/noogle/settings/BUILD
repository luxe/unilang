package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

hcp(name = "noogle_settings", deps = [
    "//code/utilities/web/automate/browser:browser_settings",
    "//code/utilities/web/google:google_search_url_devise_settings",
    "//code/utilities/web/google:google_json_url_devise_settings",
    "//code/utilities/web/bing:bing_json_url_devise_settings",
    "//code/tools/noogle/settings:query_expand_settings",
    "//code/tools/noogle/settings:word_filter_settings",
    "//code/tools/noogle/settings:token_identifier_settings",
])

hcp(name = "query_expand_settings", deps = [
])

hcp(name = "word_filter_settings", deps = [
])

hcp(name = "token_identifier_settings", deps = [
])