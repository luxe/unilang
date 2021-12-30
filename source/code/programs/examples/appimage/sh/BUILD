load("//appimage:appimage.bzl", "appimage", "appimage_test")

sh_binary(
    name = "test_sh",
    srcs = ["test.sh"],
)

appimage_test(
    name = "appimage_test_sh",
    binary = ":test_sh",
)