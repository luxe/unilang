package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "method_sorter", deps = [
"//code/transcompilers/unilang/structure/sections/method:method_item",
"//code/transcompilers/unilang/options/sections/method/sorting/method_sort_algorithms:method_sort_algorithms",
"//code/transcompilers/unilang/normal-design-printer/data:subgroup_sorted_methods",
"//code/utilities/exits:lib",
"//code/utilities/converters:lib",
"//code/utilities/types/vectors/observers:lib",
])

hcp(name = "subgroup_tag_printer", deps = [
"//code/transcompilers/unilang/options/sections/method/sorting:method_subgroup_tag_settings",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/transcompilers/unilang/doxygen_block_printer:doxygen_block_maker",
"//code/utilities/exits:lib",
"//code/utilities/converters:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/types/strings/observers/converting:lib",
])

hcp(name = "method_sorting_and_grouping_order_printer", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/normal-design-printer/data:subgroup_sorted_methods",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/structure-printer:methods_printer",
"//code/transcompilers/unilang/in-out-design-printer:object_name_resolver",
"//code/transcompilers/unilang/normal-design-printer:method_sorter",
"//code/transcompilers/unilang/normal-design-printer:subgroup_tag_printer",
"//code/utilities/converters:lib",
"//code/utilities/types/general:lib",
"//code/utilities/exits:lib",
])

hcp(name = "normal_design_printer", deps = [
"//code/transcompilers/unilang/structure-printer/export_file_settings:export_file_settings",
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/in-out-design-printer:component_struct_printer",
"//code/transcompilers/unilang/structure-printer/forward_declares:forward_declare_printer",
"//code/transcompilers/unilang/structure-printer/typedef:typedef_printer",
"//code/transcompilers/unilang/structure-printer/macro:macro_printer",
"//code/transcompilers/unilang/enum_printer:enum_section_printer",
"//code/transcompilers/unilang/normal-design-printer:method_sorting_and_grouping_order_printer",
"//code/transcompilers/unilang/structure-adjuster/methods/api_and_lifetime:api_and_lifetime_creator",
"//code/utilities/exits:lib",
"//code/utilities/converters:lib",
])