package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "wav_file_join_settings",
    deps = [
    ],
)

hcp(
    name = "wav_file_joiner",
    deps = [
        "//code/utilities/deps/external/audio_file:lib",
        "//code/utilities/peripheral/sound/wav:wav_file_join_settings",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "pitch_adjuster",
    deps = [
        "//code/utilities/deps/external/audio_file:lib",
        "//code/utilities/peripheral/sound/wav:wav_file_join_settings",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp(
    name = "tempo_adjuster",
    deps = [
        "//code/utilities/deps/external/audio_file:lib",
        "//code/utilities/peripheral/sound/wav:wav_file_join_settings",
        "//code/utilities/program/call:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
