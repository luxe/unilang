package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

#build main and deploy stuff
cc_binary(
    name = "tabtime",
    srcs = ["tabtime.cpp"],
    deps = [
        "//code/tools/tabtime:tabtime_runner"
    ]
)

hcp(name = "tabtime_runner", deps = [
    "//code/utilities/shell:lib",
])