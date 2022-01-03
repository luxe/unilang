package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "global")

# hcp(
#     name = "language_file_creator",
#     deps = [
#         "//code/utilities/filesystem/paths:lib",
#         "//code/utilities/types/converters:lib",
#         "//code/programs/transcompilers/old_unilang/language-and-theme-creator/sublime:global",
#     ],
# )

# hcp(
#     name = "reference_file_creator",
#     deps = [
#         "//code/utilities/filesystem/paths:lib",
#         "//code/utilities/streams/filestreams:lib",
#         "//code/utilities/types/converters:lib",
#         "//code/utilities/types/vectors/observers:lib",
#     ],
# )

hcp(
    name = "settings_file_creator",
    deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/converters:lib",
        "//code/programs/transcompilers/old_unilang/language-and-theme-creator/sublime:global",
        "//code/programs/transcompilers/old_unilang/language-and-theme-creator/sublime:shared",
    ],
)

hcp(
    name = "shared",
    deps = [
        "//code/utilities/filesystem/paths:lib",
    ],
)

hcp(
    name = "unilang_file_creator",
    deps = [
    	"//code/programs/transcompilers/old_unilang/language-and-theme-creator/sublime:settings_file_creator",
    ],
)

# hcp(
#     name = "stylized_reference_file_creator",
#     deps = [
#         "//code/utilities/filesystem/paths:lib",
#     ],
# )


# hcp(
#     name = "theme_file_creator",
#     deps = [
#         "//code/utilities/filesystem/paths:lib",
#         "//code/utilities/types/converters:lib",
#     ],
# )
