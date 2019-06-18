load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

def package_data(name,file_groups):

    MAIN_TAR_SUFFIX = "_tar"
    DATA_TAR_SUFFIX = "-data"
    FULL_MAIN_TAR = name + MAIN_TAR_SUFFIX
    DATA_MAIN_TAR = name + DATA_TAR_SUFFIX
    
    pkg_tar(
        name = FULL_MAIN_TAR,
        package_dir = "/usr/local/share/" + name,
        srcs = file_groups,
        mode = "0755",
    )

    pkg_tar(
        name = DATA_MAIN_TAR,
        extension = "tar.gz",
        deps = [
            ":" + FULL_MAIN_TAR,
        ],
    )