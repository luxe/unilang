package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(
    name = "language_type",
    deps = [
        "//code/utilities/linguistics/computer/types/cross/language_type:language_type_category",
        "//code/utilities/linguistics/computer/types/cross/language_type:needed_import",
        "//code/utilities/linguistics/computer/types/cross/language_type:type_size",
    ],
)

hcp(
    name = "needed_import",
    deps = [
        "type_size",
        "//code/tools/transcompilers/unilang/structure/model/sections/import:import_type",
    ],
)

hcp(
    name = "type_size",
    deps = [
    ],
)

enum_cpp(
    name = "language_type_category",
    values =
        [
            "fundamental",
            "abstract",
        ],
)
