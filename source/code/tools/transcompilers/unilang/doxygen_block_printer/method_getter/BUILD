package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "doxygen_data_getter_for_methods", deps = [
"//code/tools/transcompilers/unilang/structure/model/sections/method:method_item",
"//code/tools/transcompilers/unilang/structure/model/sections/data_member:data_member_item",
"//code/tools/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/tools/transcompilers/unilang/doxygen_block_printer:doxygen_data",
"//code/tools/transcompilers/unilang/doxygen_block_printer/method_getter/adders:main_description_adder",
"//code/tools/transcompilers/unilang/doxygen_block_printer/method_getter/adders:contract_description_adder",
"//code/tools/transcompilers/unilang/doxygen_block_printer/method_getter/adders:argument_description_adder",
"//code/tools/transcompilers/unilang/doxygen_block_printer/method_getter/adders:return_results_description_adder",
"//code/tools/transcompilers/unilang/doxygen_block_printer/method_getter/adders:suggested_return_identifier_adder",
"//code/tools/transcompilers/unilang/doxygen_block_printer/method_getter/adders:overload_note_adder",
])