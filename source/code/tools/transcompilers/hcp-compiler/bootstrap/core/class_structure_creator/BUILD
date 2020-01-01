package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = ["//code/tools/transcompilers/hcp-compiler/bootstrap/core/structure:lib",
"//code/tools/transcompilers/hcp-compiler/bootstrap/core/structure_state:lib",
"//code/tools/transcompilers/hcp-compiler/bootstrap/core/header_validator:lib",
"//code/tools/transcompilers/hcp-compiler/bootstrap/core/unicode_parser_symbols:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/utilities/types/wstrings/transformers/other:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/language_basic/multiple_relational_comparing:lib",
"//code/utilities/types/strings/transformers/casing:lib",

]
)
