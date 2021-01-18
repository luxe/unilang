package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "method_sorter",
    deps = [
        "//code/tools/transcompilers/old_unilang/design/normal/data:subgroup_sorted_methods",
        "//code/tools/transcompilers/old_unilang/structure/model/sections/method:method_item",
        "//code/utilities/linguistics/computer/frontends/parts/method/sorting/method_sort_algorithms",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp(
    name = "subgroup_tag_printer",
    deps = [
        "//code/utilities/comments/doxygen/maker:doxygen_block_maker",
        "//code/utilities/comments/doxygen/maker:doxygen_data",
        "//code/utilities/linguistics/computer/frontends/parts/method/sorting:method_subgroup_tag_settings",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/streams/filestreams:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/strings/observers/converting:lib",
    ],
)

hcp(
    name = "method_sorting_and_grouping_order_printer",
    deps = [
        "//code/tools/transcompilers/old_unilang/design/in-out:object_name_resolver",
        "//code/tools/transcompilers/old_unilang/design/normal:method_sorter",
        "//code/tools/transcompilers/old_unilang/design/normal:subgroup_tag_printer",
        "//code/tools/transcompilers/old_unilang/design/normal/data:subgroup_sorted_methods",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/tools/transcompilers/old_unilang/structure/print:methods_printer",
        "//code/tools/transcompilers/old_unilang/structure/print:shared_printer",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/converters:lib",
        "//code/utilities/types/general:lib",
    ],
)

hcp(
    name = "normal_design_printer",
    deps = [
        "//code/tools/transcompilers/old_unilang/design/in-out:component_struct_printer",
        "//code/tools/transcompilers/old_unilang/design/normal:method_sorting_and_grouping_order_printer",
        "//code/tools/transcompilers/old_unilang/enum_printer:enum_section_printer",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/adjust/methods/api_and_lifetime:api_and_lifetime_creator",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/tools/transcompilers/old_unilang/structure/print/export_file_settings",
        "//code/tools/transcompilers/old_unilang/structure/print/forward_declares:forward_declare_printer",
        "//code/tools/transcompilers/old_unilang/structure/print/macro:macro_printer",
        "//code/tools/transcompilers/old_unilang/structure/print/typedef:typedef_printer",
        "//code/utilities/program/common_actions/exits:lib",
        "//code/utilities/types/converters:lib",
    ],
)
