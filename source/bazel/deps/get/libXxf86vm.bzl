# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def libXxf86vm():
    http_archive(
        name = "libXxf86vm",
        build_file = "//bazel/deps/build_files:libXxf86vm.BUILD",
        sha256 = "f067f5e0383d845b1c20b71cb029f92161cf11fbf410cccb502898d68d6acdb2",
        strip_prefix = "libXxf86vm-92d18649e92566ccc3abeba244adabda249cce1b",
        urls = [
            "https://github.com/Unilang/libXxf86vm/archive/92d18649e92566ccc3abeba244adabda249cce1b.tar.gz",
        ],
        patches = [
            "//bazel/deps/build_files:libXxf86vm_config.patch",
        ],
        patch_args = [
            "-p1",
        ],
    )