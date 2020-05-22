package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "rgb_section",
    values = [
        "red",
        "green",
        "blue",
    ],
)

hcp(
    name = "good_bad_screen_tint_settings",
    deps = [
        "//code/utilities/peripheral/screen/good_bad:mood_setting",
        "//code/utilities/peripheral/screen/good_bad:rgb_section",
        "//code/utilities/peripheral/screen/redshift:redshift_settings",
    ],
)

hcp(
    name = "mood_setting",
    deps = [
        "//code/utilities/peripheral/screen/good_bad:gama_slider",
        "//code/utilities/peripheral/screen/good_bad:rgb_section",
    ],
)

hcp(
    name = "gama_slider",
    deps = [
    ],
)
