package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "user_repos_getter",
    deps = [
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)

hcp(
    name = "github_ssh_url_getter",
    deps = [
    ],
)

hcp(
    name = "user_forked_repos_getter",
    deps = [
        "//code/utilities/github:user_repos_getter",
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)

hcp(
    name = "repo_deleter",
    deps = [
        "//code/utilities/github:user_repos_getter",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)

hcp(
    name = "repo_getter",
    deps = [
        "//code/utilities/github:user_repos_getter",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)

hcp(
    name = "orgs_repo_getter",
    deps = [
        "//code/utilities/github:user_repos_getter",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/web:html_fetch_settings",
        "//code/utilities/web:lib",
        "//code/utilities/web:web_json_extraction_settings",
    ],
)
