package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "api_and_lifetime_creator", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/options/language-specific:c_export_settings",
"//code/transcompilers/unilang/structure-printer:shared_printer",
"//code/transcompilers/unilang/in-out-design-printer/derived_method_creators/c/constructors:shortcut_constructor_creator",
"//code/transcompilers/unilang/in-out-design-printer/derived_method_creators/c/constructors:shortcut_copy_constructor_creator",
"//code/transcompilers/unilang/in-out-design-printer/derived_method_creators/c/constructors:initialize_creator",
"//code/transcompilers/unilang/in-out-design-printer/derived_method_creators/c/constructors:copy_constructor_creator",
"//code/transcompilers/unilang/in-out-design-printer/derived_method_creators/c/other:deep_copy_creator",
"//code/transcompilers/unilang/in-out-design-printer/derived_method_creators/c/destructors:destructor_creator",
"//code/transcompilers/unilang/in-out-design-printer/derived_method_creators/c/other:good_api_creator",
])