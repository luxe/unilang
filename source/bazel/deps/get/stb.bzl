load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def stb():
    http_archive(
        name = "stb",
        build_file = "//bazel/deps/build_files:stb.BUILD",
        sha256 = "978de595fcc62448dbdc8ca8def7879fbe63245dd7f57c1898270e53a0abf95b",
        strip_prefix = "stb-052dce117ed989848a950308bd99eef55525dfb1",
        urls = [
            "https://github.com/unilang/stb/archive/052dce117ed989848a950308bd99eef55525dfb1.tar.gz",
            "https://github.com/nothings/stb/archive/052dce117ed989848a950308bd99eef55525dfb1.tar.gz",
        ],
    )