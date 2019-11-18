load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def libmagic():
    http_archive(
        name = "libmagic",
        build_file = "//bazel/deps/build_files:libmagic.BUILD",
        sha256 = "cd8133c5f38b8c91c1e4d49aa9ef23f14f15d5f8986a3616c7516532d670ac1f",
        strip_prefix = "libmagic-f3f079e766b5dceea1850b55bcc59ea6249a94f1",
        urls = [
            "https://github.com/unilang/libmagic/archive/f3f079e766b5dceea1850b55bcc59ea6249a94f1.tar.gz",
            "https://github.com/threatstack/libmagic/archive/f3f079e766b5dceea1850b55bcc59ea6249a94f1.tar.gz",
        ],
    )
