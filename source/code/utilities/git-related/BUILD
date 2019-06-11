package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
"//code/utilities/shell:lib",
"//code/utilities/filesystem/paths:lib",
]
)

hcp(name="github_uploader", deps = [
    "//code/utilities/types/char:lib",
    "//code/utilities/shell:lib",
    "//code/utilities/streams/filestreams/read_all:lib",
    "//code/utilities/filesystem/files/getting:lib",
    "//code/utilities/filesystem/paths:lib",
        "@curl",
])

hcp(name="git_setuper", deps = [
    "//code/utilities/types/char:lib",
    "//code/utilities/shell:lib",
    "//code/utilities/streams/filestreams/read_all:lib",
    "//code/utilities/filesystem/files/getting:lib",
    "//code/utilities/filesystem/paths:lib",
        "@curl",
])

hcp(name="git_updater", deps = [
    "//code/utilities/shell:lib",
])

cc_binary(
  name = "setup_git",
  srcs = ["setup_git.cpp"],
  deps = ["//code/utilities/git-related:git_setuper"]
)