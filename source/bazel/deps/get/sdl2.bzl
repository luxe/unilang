load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def sdl2():
    http_archive(
         name = "SDL2-correct",
         build_file = "//bazel/deps/build_files:sdl2.BUILD",
         sha256 = "e6a7c71154c3001e318ba7ed4b98582de72ff970aca05abc9f45f7cbdc9088cb",
         strip_prefix = "SDL2-2.0.8",
         urls = [
            "https://www.libsdl.org/release/SDL2-2.0.8.zip",
         ],
     )
    
    #http_archive(
    #    name = "sdl2_ttf",
    #    build_file = "sdl2_ttf.BUILD",
    #    sha256 = "ad7a7d2562c19ad2b71fa4ab2e76f9f52b3ee98096c0a7d7efbafc2617073c27",
    #    strip_prefix = "SDL2_ttf-2.0.14",
    #    urls = ["https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.zip"],
    #)
    #    new_http_archive(
    #      name = "SDL2image",
    #      url = "https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.3-VC.zip",
    #      build_file = "//bazel/deps/build_files:sdl2_image.BUILD",
    #      strip_prefix = "SDL2_image-2.0.3",
    #    )
