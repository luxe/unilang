# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_file")
load("//bazel/deps:deps_config.bzl", "main_mirror_url")

def lss():
    http_archive(
        name="lss" ,
        build_file="//bazel/deps/lss:build.BUILD" ,
        sha256="e21da675cf713219daa39e18ee66056f9e01655e87fe6e35740c5b5c0564ae53" ,
        strip_prefix="linux-syscall-support-be2d5a80df9a9519cab306508ce902d774da76a9" ,
        urls = [
            main_mirror_url("linux-syscall-support","be2d5a80df9a9519cab306508ce902d774da76a9"),
        ],
    )

