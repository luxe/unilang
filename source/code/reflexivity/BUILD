package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

cpp_main(
    name = "reflexive_refresh",
    deps = [
        "//code/reflexivity/docker:dockerfile_refresher",
        "//code/reflexivity/deps_define:deps_definition_refresher",
        "//code/reflexivity/tool_chain_conversion:tool_chain_conversion_refresher",
        "//code/utilities/locale:lib",
        "//code/reflexivity/settings:reflexive_refresh_settings"
    ],
)
