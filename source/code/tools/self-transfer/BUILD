load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "repo_transferer",
    deps = [
        "//code/tools/transcompilers/unilang/f2si_frontend_compiler:file_transfer_settings_getter",
        "//code/tools/transcompilers/unilang/f2si_frontend_compiler:file_transferer",
        "//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_action_getter",
        "//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
        "//code/tools/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transferer",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
    ],
)

cc_binary(
    name = "transfer-self-repo",
    srcs = ["main.cc"],
    deps = ["//code/tools/self-transfer:repo_transferer"],
)
