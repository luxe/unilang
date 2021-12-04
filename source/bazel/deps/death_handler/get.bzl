# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def deathHandler():
    http_archive(
        name="death_handler" ,
        build_file="//bazel/deps/death_handler:build.BUILD" ,
        sha256="b67c3f7a2fa6bd42588f231dc9de61a2d49b2bbab61735000ef05b2bfa272ad9" ,
        strip_prefix="DeathHandler-6b8599b81d54734e42f09c146cbde1049f1e8b69" ,
        urls = [
            "https://github.com/Unilang/DeathHandler/archive/6b8599b81d54734e42f09c146cbde1049f1e8b69.tar.gz",
        ],
    )
