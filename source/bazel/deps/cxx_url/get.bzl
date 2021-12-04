# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def cxxUrl():
    http_archive(
        name="cxx_url" ,
        build_file="//bazel/deps/cxx_url:build.BUILD" ,
        sha256="9b4ba36ee6579be8c367659ea3768ddb7745a9da00d1ac1e5cfd996bf5d40511" ,
        strip_prefix="CxxUrl-7e7af0ce97b1021eaaf687ced1f65a5bd3e7d548" ,
        urls = [
            "https://github.com/Unilang/CxxUrl/archive/7e7af0ce97b1021eaaf687ced1f65a5bd3e7d548.tar.gz",
        ],
    )
