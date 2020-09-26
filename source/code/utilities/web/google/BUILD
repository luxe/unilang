package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "google_search_url_devise_settings",
    deps = [
    ],
)

hcp(
    name = "google_search_url_deviser",
    deps = [
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/squeeze:lib",
        "//code/utilities/web/google:google_search_url_devise_settings",
    ],
)

hcp(
    name = "google_json_url_devise_settings",
    deps = [
    ],
)

hcp(
    name = "google_json_url_deviser",
    deps = [
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/strings/transformers/squeeze:lib",
        "//code/utilities/web/google:google_json_url_devise_settings",
    ],
)
