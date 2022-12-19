package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "user_repos_getter",
    interface_deps = [
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)

hcp_hdrs_derive(
    name = "github_ssh_url_getter",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "user_forked_repos_getter",
    interface_deps = [
        "//code/utilities/github:user_repos_getter",
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)

hcp_hdrs_derive(
    name = "repo_deleter",
    interface_deps = [
        "//code/utilities/github:user_repos_getter",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)

hcp_hdrs_derive(
    name = "repo_getter",
    interface_deps = [
        "//code/utilities/github:user_repos_getter",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)

hcp_hdrs_derive(
    name = "orgs_repo_getter",
    interface_deps = [
        "//code/utilities/github:user_repos_getter",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)
