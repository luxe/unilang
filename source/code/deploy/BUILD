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
])
