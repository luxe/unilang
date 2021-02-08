# Do not edit this file directly.
# It was auto-generated by: code/tools/reflexivity/reflexive_refresh

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def glib():
    http_archive(
        name = "glib",
        build_file = "//bazel/deps/glib:build.BUILD",
        sha256 = "80753e02bd0baddfa03807dccc6da4e063f272026f07fd0e05e17c6e5353b07e",
        strip_prefix = "glib-2ba0f14b5298f49dcc3b376d2bdf6505b2c32bd3",
        urls = [
            "https://github.com/Unilang/glib/archive/2ba0f14b5298f49dcc3b376d2bdf6505b2c32bd3.tar.gz",
        ],
        patches = [
            "//bazel/deps/glib/patches:glib_config.patch",
            "//bazel/deps/glib/patches:glib_config2.patch",
            "//bazel/deps/glib/patches:glib_enums.patch",
            "//bazel/deps/glib/patches:gio_enums.patch",
            "//bazel/deps/glib/patches:gnetworking.patch",
            "//bazel/deps/glib/patches:xdp_dbus.patch",
            "//bazel/deps/glib/patches:gdbus_daemon.patch",
            "//bazel/deps/glib/patches:gmoduleconf.patch",
            "//bazel/deps/glib/patches:gconstructor.patch",
        ],
        patch_args = [
            "-p1",
        ],
    )