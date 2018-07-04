package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

cpp_object(name = "regular_argument_location")

hcp(name = "stripped_unilang_type_with_qualifiers")

hcp(name = "type_qualifier_dresser", deps = [
"stripped_unilang_type_with_qualifiers",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/type_converters/type_to_hungarian/qualifier_stripper:regular_argument_location",
"//code/utilities/types/strings/transformers/appending:lib",
])

hcp(name = "type_qualifier_stripper", deps = [
"stripped_unilang_type_with_qualifiers",
"//code/utilities/types/strings/transformers/trimming:lib",
"//code/utilities/types/strings/observers/other:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/transformers/stripping:lib",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
])