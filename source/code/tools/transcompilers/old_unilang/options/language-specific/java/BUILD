package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    "java_settings",
    deps = [
        "//code/tools/transcompilers/old_unilang/options:general_options",
        "//code/tools/transcompilers/old_unilang/options/manipulation:struct_manipulation_settings",
        "//code/utilities/linguistics/computer/frontends/parts:portion_options",
    ],
)

hcp(
    "java_test_settings",
    deps = [
        "//code/tools/transcompilers/old_unilang/options:general_options",
        "//code/tools/transcompilers/old_unilang/options:test_case_attribute_settings",
        "//code/tools/transcompilers/old_unilang/options/manipulation:struct_manipulation_settings",
        "//code/utilities/linguistics/computer/frontends/parts:portion_options",
    ],
)
