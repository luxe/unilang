package(
    default_visibility = ["//visibility:public"],
)

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


cc_binary(
  name = "path_to_desktop",
  srcs = ["path_to_desktop.cpp"],
  deps = ["//code/utilities/filesystem/paths:lib"]
)

cc_binary(
  name = "current_path",
  srcs = ["current_path.cpp"],
  deps = ["//code/utilities/filesystem/paths:lib"]
)