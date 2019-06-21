package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

hcp(name = "noogle_settings", deps = [
    "//code/utilities/web/automate/browser:browser_settings",
    "//code/utilities/web/google:google_search_url_devise_settings",
    "//code/utilities/web/google:google_json_url_devise_settings",
])