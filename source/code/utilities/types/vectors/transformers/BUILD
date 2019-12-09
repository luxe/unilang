package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = [
"//code/utilities/types/strings/observers/char:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/transformers/squeeze:lib",
"//code/utilities/types/strings/transformers/other:lib",
"//code/utilities/types/strings/transformers/casing:lib",
"//code/utilities/types/strings/observers/converting:lib",
"//code/utilities/data_structures:index_mode",
"//code/utilities/data_structures/index:moded_index",
"//code/utilities/types/map:lib",
"//code/utilities/std_hackery:std_aliases",
"@boost//:range",
]
)
