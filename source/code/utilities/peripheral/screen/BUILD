package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "screen_tint_setter",deps=[
"//code/utilities/streams/filestreams:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/program/call:lib",
"//code/utilities/peripheral/screen/good_bad:rgb_section",
"//code/utilities/peripheral/screen/good_bad:good_bad_screen_tint_settings",
"//code/utilities/peripheral/screen/good_bad:mood_setting",
"//code/utilities/peripheral/screen/redshift:redshift_command_getter",
"//code/utilities/peripheral/screen/redshift:redshift_settings",
"//code/utilities/math:math",
"//code/utilities/peripheral/screen:screen_gama_setter",
])

hcp(name = "screen_gama_setter",deps=[
"//code/utilities/streams/filestreams:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/program/call:lib",
"//code/utilities/peripheral/screen/good_bad:rgb_section",
"//code/utilities/peripheral/screen/good_bad:good_bad_screen_tint_settings",
"//code/utilities/peripheral/screen/good_bad:mood_setting",
"//code/utilities/peripheral/screen/redshift:redshift_command_getter",
"//code/utilities/peripheral/screen/redshift:redshift_settings",
"//code/utilities/math:math",
])