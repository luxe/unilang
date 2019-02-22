load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

#need to make hermetic
#sudo apt-get install libsdl2-dev
#sudo apt-get install libsdl1.2-dev
#sudo apt install libjpeg9-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0
def imgui():
    http_archive(
          name = "imgui",
          build_file = "//bazel/deps/build_files:imgui.BUILD",
          strip_prefix = 'imgui-1.62',
          urls = [
            'https://github.com/unilang/imgui/archive/v1.62.tar.gz',
            'https://github.com/ocornut/imgui/archive/v1.62.tar.gz',
          ],
    )
