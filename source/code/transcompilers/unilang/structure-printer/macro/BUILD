package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "single_macro_printer", deps = [
"//code/transcompilers/unilang/structure/sections/macro:macro_item",
"//code/transcompilers/unilang/structure-printer:doxygen_block_printer",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"macro_redefinition_message_getter",
"//code/transcompilers/unilang/boilerplate_printer/extern_c:macro_define_check_getter",
"//code/transcompilers/unilang/boilerplate_printer/extern_c:macro_endif_getter",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
])

hcp(name = "macro_redefinition_message_getter", deps = [
"//code/transcompilers/unilang/structure/sections/macro:macro_item",
"//code/transcompilers/unilang/structure-printer:doxygen_block_printer",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/char:lib",
"//code/utilities/types/strings/transformers/search_replace:lib",
])


hcp(name = "macro_printer", deps = [
"//code/transcompilers/unilang/structure/sections/macro:macro_item",
"//code/transcompilers/unilang/structure-printer:doxygen_block_printer",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"single_macro_printer",
"//code/utilities/streams/filestreams:lib",
])