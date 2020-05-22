load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_jar")

def googleJavaFormat():
    http_jar(
        name = "google_java_format",
        url = "https://github.com/google/google-java-format/releases/download/google-java-format-1.7/google-java-format-1.7-all-deps.jar",
        sha256 = "0894ee02019ee8b4acd6df09fb50bac472e7199e1a5f041f8da58d08730694aa",
    )
