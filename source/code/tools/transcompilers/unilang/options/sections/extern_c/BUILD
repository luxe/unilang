package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "extern_c_guard_options",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/extern_c/guard_sections:begin_extern_c_guard_options",
        "//code/tools/transcompilers/unilang/options/sections/extern_c/guard_sections:end_extern_c_guard_options",
    ],
)
