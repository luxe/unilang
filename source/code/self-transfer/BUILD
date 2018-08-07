load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "repo_transferer", deps = [
"//code/transcompilers/unilang/f2si_frontend_compiler:file_transfer_settings_getter",
"//code/transcompilers/unilang/f2si_frontend_compiler:file_transferer",
"//code/utilities/filesystem/paths:lib",
])

cc_binary(
    name = "transfer-self-repo",
    srcs = ["main.cc"],
    deps = ["//code/self-transfer:repo_transferer"],
    linkopts = [],
)