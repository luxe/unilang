load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def chrome_drivers():
    http_archive(
        name = "chrome_drivers",
        build_file = "//bazel/deps/build_files:chrome_drivers.BUILD",
        sha256 = "ff116b6d354f97c7e789a50ca7dae15ae1899e5627c38551860ccbede13fb5c6",
        strip_prefix = "chrome-drivers-e47bfe70331bcd06420eadcb64a374fbd98bca18",
        urls = [
            "https://github.com/unilang/chrome-drivers/archive/e47bfe70331bcd06420eadcb64a374fbd98bca18.tar.gz",
        ],
    )
