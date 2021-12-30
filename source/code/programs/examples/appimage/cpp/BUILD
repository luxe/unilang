#Example of building an AppImage
load("@rules_appimage//appimage:appimage.bzl", "appimage", "appimage_test")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(name = "main")

load("@rules_appimage//appimage:appimage.bzl", "appimage")

appimage(
    name = "main_appimage",
    binary = ":main",
)