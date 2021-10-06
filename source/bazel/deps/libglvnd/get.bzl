# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def libglvnd():
    http_archive(
        name = "libglvnd",
        build_file = "//bazel/deps/libglvnd:build.BUILD",
        sha256 = "bf6c8774d7fcd6ef2372325cafe2d780ccd48a62b0b5c4abc973c4597a196ace",
        strip_prefix = "libglvnd-3e8684a739dffe1d5441362679b4ee149425e6d6",
        urls = [
            "https://github.com/Unilang/libglvnd/archive/3e8684a739dffe1d5441362679b4ee149425e6d6.tar.gz",
        ],
        patches = [
            "//bazel/deps/libglvnd/patches:p1.patch",
        ],
        patch_args = [
            "-p1",
        ],
    )
