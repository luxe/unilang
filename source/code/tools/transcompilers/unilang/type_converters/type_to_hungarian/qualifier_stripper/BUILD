package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "regular_argument_location")

hcp(name = "stripped_unilang_type_with_qualifiers")

hcp(
    name = "type_qualifier_dresser",
    deps = [
        "stripped_unilang_type_with_qualifiers",
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:regular_argument_location",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp(
    name = "type_qualifier_stripper",
    deps = [
        "stripped_unilang_type_with_qualifiers",
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
        "//code/utilities/types/strings/transformers/trimming:lib",
    ],
)
