package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
        "//code/tools/transcompilers/hcp-compiler/bootstrap/core/class_structure_creator:lib",
        "//code/tools/transcompilers/hcp-compiler/bootstrap/core/structure:lib",
    ],
)
