package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")

hcp_hdrs_derive(
    name = "word_speaker",
    interface_deps = [
        "//code/utilities/filesystem/files/temp:existing_temp_file",
        "//code/utilities/program/call:lib",
        "//code/utilities/random:lib",
        "//code/utilities/random/files:random_files",
    ],
)

hcp_hdrs_derive(
    name = "animal_crossing_speaker",
    interface_deps = [
        "//code/utilities/assets:english_sounds",
        "//code/utilities/filesystem/files/temp:existing_temp_file",
        "//code/utilities/peripheral/sound/wav:pitch_adjuster",
        "//code/utilities/peripheral/sound/wav:tempo_adjuster",
        "//code/utilities/peripheral/sound/wav:wav_file_join_settings",
        "//code/utilities/peripheral/sound/wav:wav_file_joiner",
        "//code/utilities/program/call:lib",
        "//code/utilities/random:lib",
        "//code/utilities/types/vectors/operators:lib",
    ],
)

hcp_hdrs_derive(
    name = "pinyin_speaker",
    interface_deps = [
        "//code/utilities/assets:english_sounds",
        "//code/utilities/assets:chinese_syllable_sounds",
        "//code/utilities/filesystem/files/temp:existing_temp_file",
        "//code/utilities/peripheral/sound/wav:pitch_adjuster",
        "//code/utilities/peripheral/sound/wav:tempo_adjuster",
        "//code/utilities/peripheral/sound/wav:wav_file_join_settings",
        "//code/utilities/peripheral/sound/wav:wav_file_joiner",
        "//code/utilities/peripheral/sound/mp3:mp3_file_joiner",
        "//code/utilities/program/call:lib",
        "//code/utilities/random:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
    ],
)

enum_cpp(
    name = "chinese_tone",
    values = [
        "flat",
        "rising",
        "falling_rising",
        "falling",
    ],
)