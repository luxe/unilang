load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "bazel_refresher", deps = [
"//code/utilities/filesystem/paths:lib",
])

cc_binary(
    name = "bazel_refresh",
    srcs = ["main.cc"],
    deps = ["//code/bazel_refresh:bazel_refresher"],
)