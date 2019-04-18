load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "bazel_refresher", deps = [
"//code/utilities/filesystem/paths:lib",
"//code/bazel_refresh/conversion_test:bazel_conversion_tests",
"//code/utilities/types/strings/transformers/appending:lib",
])

cc_binary(
    name = "bazel_refresh",
    srcs = ["main.cc"],
    deps = ["//code/bazel_refresh:bazel_refresher"],
)