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
    ],
)