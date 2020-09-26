package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "enum_next_function_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
        "//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)

hcp(
    name = "enum_previous_function_getter",
    deps = [
        "//code/tools/transcompilers/unilang/options/sections/enum:enum_options",
        "//code/tools/transcompilers/unilang/structure/model/sections/enum/item:enum_item",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
        "//code/utilities/types/strings/transformers/casing:lib",
    ],
)
