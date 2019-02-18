load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def cpp_taskflow():
    http_archive(
        name = "cpptaskflow",
        build_file = "//bazel/deps/build_files:cpptaskflow.BUILD",
        sha256 = "d68ccaf99903cd148946ef3b78ceeb0278962ec7192d0cc739554bb1e1c5a697",
        strip_prefix = "cpp-taskflow-67fc5c1cab8b8f72729ca5b0a97f7adb466c9f8a",
        urls = [
            "https://github.com/cpp-taskflow/cpp-taskflow/archive/67fc5c1cab8b8f72729ca5b0a97f7adb466c9f8a.tar.gz",
        ],
    )
