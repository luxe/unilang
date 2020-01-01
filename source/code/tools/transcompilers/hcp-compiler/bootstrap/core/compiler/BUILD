package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
"//code/transcompilers/hcp-compiler/bootstrap/core/class_compiler:lib",
"//code/transcompilers/hcp-compiler/bootstrap/core/global_compiler:lib",
"//code/utilities/exits:lib",
]
)
