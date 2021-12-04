# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def cppHttplib():
    http_archive(
        name="cpp_httplib" ,
        build_file="//bazel/deps/cpp_httplib:build.BUILD" ,
        sha256="166103fc4281a438e1f5b9611981f2351ab12136086404895fe5d22e5db3aff5" ,
        strip_prefix="cpp-httplib-22615f96828a72d84019b748ede01fa11d905977" ,
        urls = [
            "https://github.com/Unilang/cpp-httplib/archive/22615f96828a72d84019b748ede01fa11d905977.tar.gz",
        ],
    )
