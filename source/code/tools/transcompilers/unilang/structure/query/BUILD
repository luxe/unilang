package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "argument_direction_decider",
    deps = [
        "//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data_shared",
        "//code/tools/transcompilers/unilang/options/comment/doxygen:doxygen_parameter_direction",
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
        "//code/tools/transcompilers/unilang/structure/print/derivers:identifier_name_deriver",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
    ],
)

hcp(
    name = "closed_box_function_checker",
    deps = [
        "//code/tools/transcompilers/unilang/options/comment/doxygen:doxygen_parameter_direction",
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
        "//code/tools/transcompilers/unilang/structure/query:argument_direction_decider",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
    ],
)

hcp(
    name = "is_overload_decider",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
        "//code/utilities/types/converters:lib",
    ],
)

hcp(
    name = "duplicated_type_information_with_parent_checker",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "duplicated_identifier_information_with_parent_checker",
    deps = [
        "//code/tools/transcompilers/unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/observers/splitting:lib",
        "//code/utilities/types/strings/transformers/stripping:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "virtual_method_checker",
    deps = [
        "//code/tools/transcompilers/unilang/structure/model/sections:structure_enums",
        "//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
    ],
)

hcp(
    name = "mock_test_checker",
    deps = [
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
    ],
)

hcp(
    name = "redis_test_checker",
    deps = [
        "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
        "//code/tools/transcompilers/unilang/structure/model:structure",
    ],
)
