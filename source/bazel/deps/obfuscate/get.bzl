# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def obfuscate():
    http_archive(
        name="obfuscate" ,
        build_file="//bazel/deps/obfuscate:build.BUILD" ,
        sha256="fda8221e08853a2d15e4c9004ceaf96ecb0fd5f86830d48dff0b218c6fc63353" ,
        strip_prefix="Obfuscate-88915d0afa46448570207e36aa8cc5f714709c50" ,
        urls = [
            "https://github.com/Unilang/Obfuscate/archive/88915d0afa46448570207e36aa8cc5f714709c50.tar.gz",
        ],
    )
