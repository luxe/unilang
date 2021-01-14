package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "notation_settings",
    deps = [
        "//code/utilities/linguistics/computer/hungarian/settings:identifier_notation_settings",
        "//code/utilities/linguistics/computer/frontends/parts/sections/data_member:data_member_casing_settings",
        "//code/utilities/linguistics/computer/frontends/parts/sections/method/parameters:method_parameter_unit_settings",
        "//code/tools/transcompilers/old_unilang/options/self_describe_type:extra_type_suffix_settings",
    ],
)

hcp(
    name = "portion_options",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/sections/data_member:data_member_options",
        "//code/utilities/linguistics/computer/frontends/parts/sections/enum:enum_options",
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings:extern_c_guard_options",
        "//code/utilities/linguistics/computer/frontends/parts/header/settings:import_options",
        "//code/utilities/linguistics/computer/frontends/parts/include_guard/settings:include_guard_options",
        "//code/utilities/linguistics/computer/frontends/parts/sections/inheritance:inheritance_options",
        "//code/utilities/linguistics/computer/frontends/parts/sections/macro:macro_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/linguistics/computer/frontends/parts/sections/method:method_options",
        "//code/utilities/linguistics/computer/frontends/parts/sections/namespace:namespace_options",
        "//code/utilities/linguistics/computer/frontends/parts/sections/type:type_options",
        "//code/utilities/linguistics/computer/frontends/parts/sections/typedef:typedef_options",
    ],
)
