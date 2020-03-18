package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "single_macro_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/macro:macro_item",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"macro_redefinition_message_getter",
"//code/tools/transcompilers/unilang/boilerplate_printer/extern_c:macro_define_check_getter",
"//code/tools/transcompilers/unilang/boilerplate_printer/extern_c:macro_endif_getter",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/converters:lib",
"//code/utilities/types/strings/transformers/trimming:lib",
])

hcp(name = "macro_redefinition_message_getter", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/macro:macro_item",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/types/char:lib",
"//code/utilities/types/strings/transformers/search_replace:lib",
])


hcp(name = "macro_printer", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/macro:macro_item",
"//code/tools/transcompilers/unilang/structure/print:doxygen_block_printer",
"//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
"single_macro_printer",
"//code/utilities/streams/filestreams:lib",
])