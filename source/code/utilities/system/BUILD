package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")


hcp(name = "installed_programs_checker", deps = [
    "//code/utilities/system:lib",
    "//code/utilities/system:check_installed_program_settings"
])

hcp(name = "check_installed_program_settings", deps = [
])

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = ["//code/utilities/program/call:lib"]
)

cc_binary(
  name = "env",
  srcs = ["env.cpp"],
  deps = ["//code/utilities/system:lib"]
)