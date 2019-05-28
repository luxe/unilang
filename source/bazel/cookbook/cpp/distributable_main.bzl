load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

def distributable_cpp_main(name,data,description,depends=[],deps=[]):

    cpp_main(name,deps)

    amd_name = name + "-debian-amd64"
    pkg_deb(
        name = amd_name,
        data = ":debian-data",
        package = name,
        architecture = "amd64",
        maintainer = "Trevor Hickey <TrevorJamesHickey@gmail.com>",
        version = "1.0",
        description = description,
        homepage = "none",
        depends = depends,
    )

    all_name = name + "-debian-all"
    pkg_deb(
        name = all_name,
        data = ":debian-data",
        package = name,
        architecture = "all",
        maintainer = "Trevor Hickey <TrevorJamesHickey@gmail.com>",
        version = "1.0",
        description = description,
        homepage = "none",
        depends = depends,
    )
