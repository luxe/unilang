package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp(
    name = "notation_settings",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/data_member:data_member_casing_settings",
        "//code/utilities/linguistics/computer/frontends/parts/method/parameters:method_parameter_unit_settings",
        "//code/utilities/linguistics/computer/hungarian/settings:identifier_notation_settings",
        "//code/utilities/linguistics/computer/types/self_describe_type:extra_type_suffix_settings",
    ],
)

hcp(
    name = "portion_options",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts/data_member:data_member_options",
        "//code/utilities/linguistics/computer/frontends/parts/enum:enum_options",
        "//code/utilities/linguistics/computer/frontends/parts/extern_c/settings:extern_c_guard_options",
        "//code/utilities/linguistics/computer/frontends/parts/header/settings:import_options",
        "//code/utilities/linguistics/computer/frontends/parts/include_guard/settings:include_guard_options",
        "//code/utilities/linguistics/computer/frontends/parts/inheritance:inheritance_options",
        "//code/utilities/linguistics/computer/frontends/parts/macro:macro_options",
        "//code/utilities/linguistics/computer/frontends/parts/meta/settings:meta_options",
        "//code/utilities/linguistics/computer/frontends/parts/method:method_options",
        "//code/utilities/linguistics/computer/frontends/parts/namespace:namespace_options",
        "//code/utilities/linguistics/computer/frontends/parts/type:type_options",
        "//code/utilities/linguistics/computer/frontends/parts/typedef:typedef_options",
    ],
)

hcp(
    name = "general_options",
    deps = [
        "//code/utilities/comments/code/settings:comment_settings",
        "//code/utilities/linguistics/computer/frontends/parts/filesystem:filesystem_settings",
    ],
)

hcp(
    name = "module_settings",
    deps = [
        "//code/utilities/linguistics/computer/frontends/parts:general_options",
        "//code/utilities/linguistics/computer/frontends/parts:notation_settings",
        "//code/utilities/linguistics/computer/frontends/parts:portion_options",
    ],
)
