# Do not edit this file directly.
# It was auto-generated by: code/programs/reflexivity/reflexive_refresh


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def sdl2():
    http_archive(
        name="sdl2" ,
        build_file="//bazel/deps/sdl2:build.BUILD" ,
        sha256="d532a339c0d33c4a090983a32017798e9108873dce445e4b617a0f726f90d081" ,
        strip_prefix="SDL-mirror-36ea2544f08508f42d5193e175d3a269c3b95bdf" ,
        urls = [
            "https://github.com/Unilang/SDL-mirror/archive/36ea2544f08508f42d5193e175d3a269c3b95bdf.tar.gz",
        ],        patches = [
            "//bazel/deps/sdl2/patches:config.patch",
            "//bazel/deps/sdl2/patches:gen_files.patch",
        ],
        patch_args = [
            "-p1",
        ],
        patch_cmds = [
            "sed -i '1s/^/#include <stdlib.h>\\n/' src/dynapi/SDL_dynapi.c",
            "sed -i '1s/^/#include <stdio.h>\\n/' src/dynapi/SDL_dynapi.c",
            "sed -i 's#fn = dlsym#fn = NULL;\\/\\/#g' src/thread/pthread/SDL_systhread.c",
            "sed -i 's#ppthread_setname_np = #ppthread_setname_np = NULL;\\/\\/#g' src/thread/pthread/SDL_systhread.c",
        ],

    )
