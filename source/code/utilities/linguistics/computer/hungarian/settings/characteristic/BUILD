package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

cpp_object(name = "hungarian_characteristic")

hcp(
    name = "hungarian_characteristic_qualifier",
    deps = ["//code/utilities/linguistics/computer/hungarian/settings/characteristic:hungarian_characteristic"],
)

hcp(
    name = "hungarian_characteristic_trump_rules",
    deps = ["//code/utilities/linguistics/computer/hungarian/settings/characteristic:hungarian_characteristic"],
)

hcp(
    name = "hungarian_characteristic_settings",
    deps = [
        "hungarian_characteristic_qualifier",
        "hungarian_characteristic_trump_rules",
    ],
)
