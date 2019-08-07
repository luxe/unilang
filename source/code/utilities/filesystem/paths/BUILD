package(
    default_visibility = ["//visibility:public"],
)
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

cc_library(
    name = "lib",
    srcs = ["lib.cpp"],
    hdrs = ["lib.hpp"],
    deps = [
"//code/utilities/shell:lib",
"//code/utilities/filesystem/files/observers/lstat_wrap:lib",
"@boost//:filesystem",
"@boost//:range",
],
)


cpp_main(
  name = "path_to_desktop",
  deps = ["//code/utilities/filesystem/paths:lib"]
)

cpp_main(
  name = "current_path",
  deps = ["//code/utilities/filesystem/paths:lib"]
)

cpp_main(
  name = "bazel_workspace_directory",
  deps = ["//code/utilities/filesystem/paths:lib"]
)

cpp_main(
  name = "bazel_derived_root",
  deps = ["//code/utilities/filesystem/paths:lib"]
)