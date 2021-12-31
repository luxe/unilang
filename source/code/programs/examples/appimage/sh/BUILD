#Example of building an AppImage
load("@rules_appimage//appimage:appimage.bzl", "appimage", "appimage_test")

package(
    default_visibility = ["//visibility:public"],
)

sh_binary(
    name = "test_sh",
    srcs = ["test.sh"],
)

appimage_test(
    name = "appimage_test_sh",
    binary = ":test_sh",
)
