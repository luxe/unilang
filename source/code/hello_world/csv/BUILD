load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = ["//code/utilities/formats/csv:csv_extractor","//code/utilities/printers:lib","//code/utilities/program/call:lib"],
)