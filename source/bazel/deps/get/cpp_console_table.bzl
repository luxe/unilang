load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def cppConsoleTable():
    http_archive(
        name = "cpp_console_table",
        build_file = "//bazel/deps/build_files:cpp_console_table.BUILD",
        sha256 = "8e4f9edc7f6fd3f2de3f2020c8ef51098c35c365e5f4a3670ee279065b96f93b",
        strip_prefix = "CppConsoleTable-958478a211bcb4d2506243c63a34445eb2e13b5d",
        urls = [
            "https://github.com/unilang/CppConsoleTable/archive/958478a211bcb4d2506243c63a34445eb2e13b5d.tar.gz",
            "https://github.com/DenisSamilton/CppConsoleTable/archive/ff1ebb9ab40f060bda7c520bb1afb6d3c42b7ea6.tar.gz",
        ],
    )