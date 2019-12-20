load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("@rules_pkg//:pkg.bzl", "pkg_tar", "pkg_deb")
load("//bazel/cookbook/data:package_data.bzl", "package_data")

def distributable_data(name,description,file_groups):

    EVERYTHING_EXTENSION = "-debian-all"
    MAINTAINER = "Trevor Hickey <TrevorJamesHickey@gmail.com>"
    DEFAULT_VERSION = "1.0"
    DEFAULT_HOMEPAGE = "none"
    DATA_TARGET = ":" + name + "-data"
    
    package_data(name = name,
                 file_groups = file_groups)

    all_name = name + EVERYTHING_EXTENSION
    pkg_deb(
        name = all_name,
        data = DATA_TARGET,
        package = name,
        architecture = "all",
        maintainer = MAINTAINER,
        version = DEFAULT_VERSION,
        description = description,
        homepage = DEFAULT_HOMEPAGE,
    )
