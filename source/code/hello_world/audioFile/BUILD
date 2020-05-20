load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = [
        "@AudioFile//:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/peripheral/sound/wav:wav_file_join_settings",
        "//code/utilities/peripheral/sound/wav:wav_file_joiner",
        "//code/utilities/assets:english_sounds",
        "//code/utilities/peripheral/sound/wav:pitch_adjuster",
        "//code/utilities/peripheral/sound/wav:tempo_adjuster",
        "//code/utilities/filesystem/files/temp:existing_temp_file",
        "//code/utilities/linguistics/speak:animal_crossing_speaker",
    ],
)