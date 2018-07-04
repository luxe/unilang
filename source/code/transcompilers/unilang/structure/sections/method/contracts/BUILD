package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "contract_postcondition", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "contract_precondition", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "method_contracts_section", deps = [
"contract_postcondition",
"contract_precondition",
"//code/utilities/types/vectors/operators:lib"
])