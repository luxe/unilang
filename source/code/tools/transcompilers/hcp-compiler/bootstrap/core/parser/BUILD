package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
	deps = [
	"//code/tools/transcompilers/hcp-compiler/bootstrap/core/class_parser:lib",
	"//code/tools/transcompilers/hcp-compiler/bootstrap/core/global_parser:lib",
	"//code/utilities/exits:lib"
]
)
