# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def sDLImage():
    http_archive(
        name = "SDL_image",
        build_file = "//bazel/deps/SDL_image:build.BUILD",
        sha256 = "f33b3d6c41a4be188414515ee76cd8a281d5866c1a1c4fc277f74c50dd64d4a5",
        strip_prefix = "SDL_image-b7c6f50dc61c7a02894caed798179ad71a4e452a",
        urls = [
            "https://github.com/Unilang/SDL_image/archive/b7c6f50dc61c7a02894caed798179ad71a4e452a.tar.gz",
        ],
    )