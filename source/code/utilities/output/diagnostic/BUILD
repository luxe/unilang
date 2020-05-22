package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object("diagnostic_color")

cpp_object("diagnostic_stream")

hcp(
    name = "diagnostic_settings",
    deps = [
        "//code/utilities/output/diagnostic:diagnostic_color",
        "//code/utilities/output/diagnostic:diagnostic_stream",
    ],
)

hcp(
    name = "diagnostic_printer",
    deps = [
        "//code/utilities/colors:lib",
        "//code/utilities/output/diagnostic:diagnostic_settings",
    ],
)
