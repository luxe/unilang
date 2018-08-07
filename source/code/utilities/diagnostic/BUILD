package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

cpp_object("diagnostic_color")
cpp_object("diagnostic_stream")

hcp(name = "diagnostic_settings", deps = [
"//code/utilities/diagnostic:diagnostic_color",
"//code/utilities/diagnostic:diagnostic_stream",
])

hcp(name = "diagnostic_printer", deps = [
"//code/utilities/diagnostic:diagnostic_settings",
"//code/utilities/colors:lib",
])