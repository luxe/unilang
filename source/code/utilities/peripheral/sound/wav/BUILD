package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "wav_file_join_settings",deps=[
])

hcp(name = "wav_file_joiner",deps=[
    "//code/utilities/peripheral/sound/wav:wav_file_join_settings",
    "//code/utilities/types/vectors/operators:lib",
    "@AudioFile//:lib",
    
])

hcp(name = "pitch_adjuster",deps=[
    "//code/utilities/peripheral/sound/wav:wav_file_join_settings",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/program/call:lib",
    "@AudioFile//:lib",
    
])

hcp(name = "tempo_adjuster",deps=[
    "//code/utilities/peripheral/sound/wav:wav_file_join_settings",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/program/call:lib",
    "@AudioFile//:lib",
    
])