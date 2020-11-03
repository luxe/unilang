package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "api_and_lifetime_creator",
    deps = [
        "//code/tools/transcompilers/old_unilang/design/in-out/derived_method_creators/c/constructors:copy_constructor_creator",
        "//code/tools/transcompilers/old_unilang/design/in-out/derived_method_creators/c/constructors:initialize_creator",
        "//code/tools/transcompilers/old_unilang/design/in-out/derived_method_creators/c/constructors:shortcut_constructor_creator",
        "//code/tools/transcompilers/old_unilang/design/in-out/derived_method_creators/c/constructors:shortcut_copy_constructor_creator",
        "//code/tools/transcompilers/old_unilang/design/in-out/derived_method_creators/c/destructors:destructor_creator",
        "//code/tools/transcompilers/old_unilang/design/in-out/derived_method_creators/c/other:deep_copy_creator",
        "//code/tools/transcompilers/old_unilang/design/in-out/derived_method_creators/c/other:good_api_creator",
        "//code/tools/transcompilers/old_unilang/options/language-specific/c:c_export_settings",
        "//code/tools/transcompilers/old_unilang/structure/model:structure",
        "//code/tools/transcompilers/old_unilang/structure/print:shared_printer",
    ],
)
