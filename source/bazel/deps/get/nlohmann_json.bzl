load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def nlohmannJson():
    http_archive(
        name = "nlohmann_json",
        build_file = "//bazel/deps/build_files:nlohmann_json.BUILD",
        sha256 = "e0b1fc6cc6ca05706cce99118a87aca5248bd9db3113e703023d23f044995c1d",
        strip_prefix = "json-3.5.0",
        urls = [
            "https://github.com/unilang/json/archive/v3.5.0.tar.gz",
            "https://github.com/nlohmann/json/archive/v3.5.0.tar.gz",
        ],
    )
