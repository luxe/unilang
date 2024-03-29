# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_file")
load("//bazel/deps:deps_config.bzl", "main_mirror_url")

def freeGLUT():
    http_archive(
        name="FreeGLUT" ,
        build_file="//bazel/deps/FreeGLUT:build.BUILD" ,
        sha256="90828907ea4e30a79ce7f36c5b3e4d60039912d92ec17788fd709c955f4d0a04" ,
        strip_prefix="FreeGLUT-349a23dcc1264a76deb79962d1c90462ad0c6f50" ,
        urls = [
            main_mirror_url("FreeGLUT","349a23dcc1264a76deb79962d1c90462ad0c6f50"),
        ],        patches = [
            "//bazel/deps/FreeGLUT/patches:p1.patch",
        ],
        patch_args = [
            "-p1",
        ],

    )

