# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def gflags():
    http_archive(
        name="gflags" ,
        sha256="ed82ef64389409e378fc6ae55b8b60f11a0b4bbb7e004d5ef9e791f40af19a6e" ,
        strip_prefix="gflags-f7388c6655e699f777a5a74a3c9880b9cfaabe59" ,
        urls = [
            "https://github.com/Unilang/gflags/archive/f7388c6655e699f777a5a74a3c9880b9cfaabe59.tar.gz",
        ],
    )
