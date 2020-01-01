package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

cpp_object(name = "hungarian_characteristic")
hcp(name = "hungarian_characteristic_qualifier",deps = ["//code/transcompilers/unilang/options/hungarian/characteristic:hungarian_characteristic"])
hcp(name = "hungarian_characteristic_trump_rules",deps = ["//code/transcompilers/unilang/options/hungarian/characteristic:hungarian_characteristic"])
hcp(name = "hungarian_characteristic_settings",deps = [
"hungarian_characteristic_qualifier",
"hungarian_characteristic_trump_rules"
])