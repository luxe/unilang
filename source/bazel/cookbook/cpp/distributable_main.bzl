load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")

def distributable_cpp_main(name,data,description,depends=[],deps=[]):

    AMD_64_EXTENSION = "-debian-amd64"
    EVERYTHING_EXTENSION = "-debian-all"
    MAINTAINER = "Trevor Hickey <TrevorJamesHickey@gmail.com>"
    DEFAULT_VERSION = "1.0"
    DEFAULT_HOMEPAGE = "none"
    
    cpp_main(name,deps)
    
    package_binaries(name = name,
                 binary_targets = ["//code/tools/deskstock:deskstock"])

    amd_name = name + AMD_64_EXTENSION
    pkg_deb(
        name = amd_name,
        data = ":deskstock-data",
        package = name,
        architecture = "amd64",
        maintainer = MAINTAINER,
        version = DEFAULT_VERSION,
        description = description,
        homepage = DEFAULT_HOMEPAGE,
        depends = depends,
    )

    all_name = name + EVERYTHING_EXTENSION
    pkg_deb(
        name = all_name,
        data = ":deskstock-data",
        package = name,
        architecture = "all",
        maintainer = MAINTAINER,
        version = DEFAULT_VERSION,
        description = description,
        homepage = DEFAULT_HOMEPAGE,
        depends = depends,
    )
