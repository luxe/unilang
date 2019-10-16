load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def fluxcapacitor():
    http_archive(
        name = "fluxcapacitor",
        build_file = "//bazel/deps/build_files:fluxcapacitor.BUILD",
        sha256 = "78e396bb58804b5f6728578392abc489048b4ee6d1fb6e351f506ebab451bde1",
        strip_prefix = "fluxcapacitor-f6c7f0775597c1141e718ce32bf79268ac8c33ef",
        urls = [
            "https://github.com/unilang/fluxcapacitor/archive/f6c7f0775597c1141e718ce32bf79268ac8c33ef.tar.gz",
            "https://github.com/majek/fluxcapacitor/archive/f6c7f0775597c1141e718ce32bf79268ac8c33ef.tar.gz",
        ],
    )