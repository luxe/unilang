load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def toolchains():

    git_repository(
        name = 'co_vsco_bazel_toolchains',
        remote = 'https://github.com/vsco/bazel-toolchains',
        tag = 'v64.0.3282.167',
    )

    # load("@co_vsco_bazel_toolchains//toolchains:repositories.bzl", "bazel_toolchains_repositories")
    # bazel_toolchains_repositories()
