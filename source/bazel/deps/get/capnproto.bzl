load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def capnproto():
    http_archive(
        name = "capnproto",
        build_file = "//bazel/deps/build_files:capnproto.BUILD",
        sha256 = "fd53ad53701e41d829dba551df546916e05aaa0613d00e28f881d26a2d5a7976",
        strip_prefix = "capnproto-4972582de4761910a6acbcbba16c0d23bb0f48a0",
        urls = [
            "https://github.com/unilang/capnproto/archive/4972582de4761910a6acbcbba16c0d23bb0f48a0.tar.gz",
            "https://github.com/capnproto/capnproto/archive/4972582de4761910a6acbcbba16c0d23bb0f48a0.tar.gz",
        ],
    )