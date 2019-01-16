package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "include_guard_wrap_printer", deps = [
"//code/transcompilers/unilang/structure/model/sections/meta:meta_section",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/types/strings/transformers/casing:case_modifier",
"//code/utilities/streams/filestreams:lib",
])

hcp(name = "code_wrap_printer", deps = [
"//code/transcompilers/unilang/structure/model/sections/meta:meta_section",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/utilities/streams/filestreams:lib",
])

hcp(name = "boilerplate_printer", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/boilerplate_printer/meta_block:meta_block_printer",
"//code/transcompilers/unilang/boilerplate_printer:code_wrap_printer",
"//code/transcompilers/unilang/boilerplate_printer/header:header_printer",
"//code/transcompilers/unilang/boilerplate_printer:include_guard_wrap_printer",
"//code/transcompilers/unilang/boilerplate_printer/extern_c:extern_wrap_printer",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])