load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def rapidJson():
    http_archive(
        name = "com_github_tencent_rapidjson",
        build_file = "//bazel/deps/build_files:rapidjson.BUILD",
        sha256 = "bf7ced29704a1e696fbccf2a2b4ea068e7774fa37f6d7dd4039d0787f8bed98e",
        strip_prefix = "rapidjson-1.1.0",
        urls = [
            "https://github.com/unilang/rapidjson/archive/v1.1.0.tar.gz",
            "https://github.com/Tencent/rapidjson/archive/v1.1.0.tar.gz",
        ],
    )
