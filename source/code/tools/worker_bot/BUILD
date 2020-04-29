package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "worker_bot",
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/program/call/process_spawn:process_spawner",
        "//code/utilities/time/sleeping:lib",
        "//code/utilities/program/wrappers/sendmail:sendmail_settings",
        "//code/utilities/program/wrappers/sendmail:sendmail_settings_getter",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/tools/worker_bot:worker_bot",
            "//code/utilities/program/call:lib"],
)
