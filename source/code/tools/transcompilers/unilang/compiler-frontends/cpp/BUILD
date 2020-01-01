package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "cpp_exporter", deps = [
"//code/transcompilers/unilang/structure/model:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/options/language-specific:cpp_export_settings",
"//code/transcompilers/unilang/structure/model:inlined_structures",
"//code/transcompilers/unilang/structure/adjust:structure_adjuster",
"//code/transcompilers/unilang/structure/print:file_printer",
"//code/transcompilers/unilang/type_converters/unilang-type-to-language-type-converter/languages:source_language",
])

hcp(name = "cpp_options_getter", deps = [
"//code/transcompilers/unilang/options/language-specific:cpp_export_settings",
"//code/transcompilers/unilang/options/sections/meta/organizations:organization",
"//code/transcompilers/unilang/structure/model:structure",
"//code/utilities/exits:lib",
"//code/transcompilers/unilang/structure/model:inlined_structures",
"//code/utilities/life:company_getter",
])
