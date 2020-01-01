package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = ["//code/tools/transcompilers/hcp-compiler/bootstrap/core/structure:lib",
	"//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/transformers/removing:lib",
    "//code/utilities/types/wstrings/transformers/trimming:lib",
    "//code/utilities/types/wstrings/transformers/other:lib",
]
)
