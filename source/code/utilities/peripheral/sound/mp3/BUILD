#combine mp3s
#mp3wrap output.mp3 *.mp3
package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")


hcp(
    name = "mp3_file_joiner",
    deps = [
        "//code/utilities/peripheral/sound/wav:wav_file_join_settings",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/program/call:lib",
    ],
)
