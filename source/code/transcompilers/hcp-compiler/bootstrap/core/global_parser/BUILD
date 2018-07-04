package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = ["//code/transcompilers/hcp-compiler/bootstrap/core/structure:lib",
	"//code/transcompilers/hcp-compiler/bootstrap/core/global_structure_creator:lib",]
)
