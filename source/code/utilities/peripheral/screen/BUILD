package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "screen_tint_setter",
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/math",
        "//code/utilities/peripheral/screen:screen_gama_setter",
        "//code/utilities/peripheral/screen/good_bad:good_bad_screen_tint_settings",
        "//code/utilities/peripheral/screen/good_bad:mood_setting",
        "//code/utilities/peripheral/screen/good_bad:rgb_section",
        "//code/utilities/peripheral/screen/redshift:redshift_command_getter",
        "//code/utilities/peripheral/screen/redshift:redshift_settings",
        "//code/utilities/program/call:lib",
        "//code/utilities/streams/filestreams:lib",
    ],
)

hcp(
    name = "screen_gama_setter",
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/math",
        "//code/utilities/peripheral/screen/good_bad:good_bad_screen_tint_settings",
        "//code/utilities/peripheral/screen/good_bad:mood_setting",
        "//code/utilities/peripheral/screen/good_bad:rgb_section",
        "//code/utilities/peripheral/screen/redshift:redshift_command_getter",
        "//code/utilities/peripheral/screen/redshift:redshift_settings",
        "//code/utilities/program/call:lib",
        "//code/utilities/streams/filestreams:lib",
    ],
)
