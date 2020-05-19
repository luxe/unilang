load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def xorgXinput():
    http_archive(
        name = "xorg_xinput",
        build_file = "//bazel/deps/build_files:xorg_xinput.BUILD",
        sha256 = "e574041f0997511519137ba290cda39884bc490b0e991ce4447d37112d1becdb",
        strip_prefix = "xorg-xinput-32314d73b811fff16a11c402778869ba4525e59b",
        urls = [
            "https://github.com/Unilang/xorg-xinput/archive/32314d73b811fff16a11c402778869ba4525e59b.tar.gz",
            "https://github.com/freedesktop/xorg-xinput/archive/32314d73b811fff16a11c402778869ba4525e59b.tar.gz",
        ],
    )