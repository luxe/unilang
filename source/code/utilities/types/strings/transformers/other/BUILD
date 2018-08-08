package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "lib",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps = ["//code/utilities/types/char:lib",

"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/observers/columns:lib",
"//code/utilities/types/strings/observers/char:lib",
"//code/utilities/types/strings/observers/indexing:lib",
"//code/utilities/types/strings/observers/converting:lib",
"//code/utilities/types/strings/creators:lib",
"//code/utilities/types/booleans:lib",
"@com_github_boost_algorithm//:algorithm"
]
)
