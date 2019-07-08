package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

hcp(name = "noogle_settings", deps = [
    "//code/utilities/web/automate/browser:browser_settings",
    "//code/utilities/web/search_engines:search_engine_url_devise_settings",
    "//code/tools/noogle/settings:query_expand_settings",
    "//code/tools/noogle/settings:url_filter_settings",
    "//code/tools/noogle/settings:word_filter_settings",
    "//code/tools/noogle/settings:token_identifier_settings",
    "//code/tools/noogle/settings:search_engine_credentials",
    "//code/tools/noogle/settings:result_to_html_settings",
    "//code/tools/noogle/settings:html_sanitize_settings",
    "//code/tools/noogle/settings:show_results_settings",
])

hcp(name = "query_expand_settings", deps = [
])

hcp(name = "word_filter_settings", deps = [
])

hcp(name = "token_identifier_settings", deps = [
])

hcp(name = "url_filter_settings", deps = [
])

hcp(name = "search_engine_credentials", deps = [
])

hcp(name = "result_to_html_settings", deps = [
])

hcp(name = "html_sanitize_settings", deps = [
])

hcp(name = "show_results_settings", deps = [
    "//code/utilities/chart/ascii:chart_get_settings",
])

hcp(name = "default_settings_getter", deps = [
    "//code/tools/noogle/settings:noogle_settings",
    "//code/utilities/web/chrome/driver:chrome_driver_selector",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/secret:secret_getter",
    "//code/tools/noogle/settings:query_expand_settings",
    "//code/utilities/types/vectors/operators:lib",
])