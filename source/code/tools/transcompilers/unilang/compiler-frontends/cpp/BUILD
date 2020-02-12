package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "cpp_exporter", deps = [
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/tools/transcompilers/unilang/contributor:contributor",
"//code/tools/transcompilers/unilang/options/language-specific:cpp_export_settings",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
"//code/tools/transcompilers/unilang/structure/adjust:structure_adjuster",
"//code/tools/transcompilers/unilang/structure/print:file_printer",
"//code/tools/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])

hcp(name = "cpp_options_getter", deps = [
"//code/tools/transcompilers/unilang/options/language-specific:cpp_export_settings",
"//code/tools/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/tools/transcompilers/unilang/structure/model:structure",
"//code/utilities/program/common_actions/exits:lib",
"//code/tools/transcompilers/unilang/structure/model:inlined_structures",
"//code/utilities/personal/life:company_getter",
])
