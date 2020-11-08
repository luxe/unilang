load("//bazel/rules/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = [
        "@nlohmann_json",
        "//code/utilities/formats/json/patching:json_patch_builder"
    ],
)
