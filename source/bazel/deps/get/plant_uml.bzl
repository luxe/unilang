load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def plant_uml():
    http_archive(
        name = "plantuml",
        build_file = "//bazel/deps/build_files:plantuml.BUILD",
        sha256 = "53eecf601da9e3f495e1861f064b76e337346f51aa6069e750f1b8ec78b89a55",
        urls = [
            "https://downloads.sourceforge.net/project/plantuml/1.2018.12/plantuml-jar-asl-1.2018.12.zip?r=https%3A%2F%2Fsourceforge.net%2Fprojects%2Fplantuml%2Ffiles%2Fplantuml-jar-asl-1.2018.12.zip%2Fdownload&ts=1542658651",
        ],
    )
