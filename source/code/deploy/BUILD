load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_binary(
    name = "deploy",
    srcs = ["main.cpp"],
    deps = [
    "//code/utilities/locale:lib",
    "//code/deploy:software_deployer"
    ],
)


hcp(name = "software_deployer", deps = [
    "//code/utilities/filesystem/files/getting:lib",
    "//code/utilities/filesystem/paths:lib",
    "//code/utilities/types/strings/observers/path:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/tools/deskstock:documentation_getter",
    
    "//code/utilities/pdf:pdf_settings",
    "//code/utilities/pdf:pdf_creator",
    "//code/utilities/filesystem/files/moving:lib",
])
