# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def chineseSyllableSounds():
    http_archive(
        name="chinese_syllable_sounds" ,
        build_file="//bazel/deps/chinese_syllable_sounds:build.BUILD" ,
        sha256="52849b2317e897ba333a9ae0dd55f7187a7198619fab74e555e9919c750942a0" ,
        strip_prefix="chinese_syllable_sounds-042305a69752a5beef8e6e0f66942edc370f7dcc" ,
        urls = [
            "https://github.com/Unilang/chinese_syllable_sounds/archive/042305a69752a5beef8e6e0f66942edc370f7dcc.tar.gz",
        ],
    )
