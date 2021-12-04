# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def olcPixelGameEngine():
    http_archive(
        name="olcPixelGameEngine" ,
        build_file="//bazel/deps/olcPixelGameEngine:build.BUILD" ,
        sha256="ab65c698e5254ce12217d817750d1b1aa0a3720abb7178ed06419ee8cf7df25e" ,
        strip_prefix="olcPixelGameEngine-8418b7d616c417ea46129d981380046004804fb3" ,
        urls = [
            "https://github.com/Unilang/olcPixelGameEngine/archive/8418b7d616c417ea46129d981380046004804fb3.tar.gz",
        ],
    )
