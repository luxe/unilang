#Example of building an AppImage
load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(name = "main")

load("@rules_appimage//appimage:appimage.bzl", "appimage")

appimage(
    name = "main_appimage",
    binary = ":main",
)