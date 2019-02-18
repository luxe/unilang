load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def sdl2():
    http_archive(
        name = 'SDL2',
        urls = [
          'https://www.libsdl.org/release/SDL2-devel-2.0.8-VC.zip',
        ],
        build_file = "//bazel/deps/build_files:sdl2.BUILD",
        strip_prefix = 'SDL2-2.0.8',
    )
#    new_http_archive(
#      name = "SDL2image",
#      url = "https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.3-VC.zip",
#      build_file = "//bazel/deps/build_files:sdl2_image.BUILD",
#      strip_prefix = "SDL2_image-2.0.3",
#    )
