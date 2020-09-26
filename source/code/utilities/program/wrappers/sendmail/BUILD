package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "sendmail_settings",
    deps = [
    ],
)

hcp(
    name = "sendmail_settings_getter",
    deps = [
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/program/wrappers/sendmail:sendmail_settings",
    ],
)

hcp(
    name = "sendmail_sender",
    deps = [
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/temp:existing_temp_file",
        "//code/utilities/filesystem/files/temp:temp_file",
        "//code/utilities/program/call:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/program/wrappers/sendmail:sendmail_settings",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "ssmtp_conf_maker",
    deps = [
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/personal/secret:secret_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
