# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def buildtools():
    http_archive(
        name = "buildtools",
        build_file = "//bazel/deps/build_files:buildtools.BUILD",
        sha256 = "bacae31ebfa1dbed55b9db531038d1e2c5fae9c7d056f9ff9947ae9bcfe0c6ae",
        strip_prefix = "buildtools-c98e381e8651e97d6da52122b288ec2ba6c392ec",
        urls = [
            "https://github.com/Unilang/buildtools/archive/c98e381e8651e97d6da52122b288ec2ba6c392ec.tar.gz",
        ],
    )