# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/build_gen

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def mesaGlu():
    http_archive(
        name = "mesa_glu",
        build_file = "//bazel/deps/mesa_glu:build.BUILD",
        sha256 = "11e1eff80197b0d192040c520522dfa6919170c202b7c00b647ee70a3ee10887",
        strip_prefix = "mesa-glu-dd4e18eb7557a31a3c8318d6612801329877c745",
        urls = [
            "https://github.com/Unilang/mesa-glu/archive/dd4e18eb7557a31a3c8318d6612801329877c745.tar.gz",
        ],
        patch_cmds = [
            "sed -i 's/register/ /g' src/libnurbs/internals/varray.cc",
            "sed -i '1s/^/#include <limits.h>\\n/' src/libtess/priorityq-heap.c",
        ],
    )
