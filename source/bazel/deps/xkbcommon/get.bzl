# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def xkbcommon():
    http_archive(
        name="xkbcommon" ,
        build_file="//bazel/deps/xkbcommon:build.BUILD" ,
        sha256="bb9b5784267331ac5bb1eed7c38d42ce85e545d7bf63168094c71fbb32093681" ,
        strip_prefix="libxkbcommon-bdb009bb0cd925b062ec922bf031042d6209eb29" ,
        urls = [
            "https://github.com/Unilang/libxkbcommon/archive/bdb009bb0cd925b062ec922bf031042d6209eb29.tar.gz",
        ],
    )
