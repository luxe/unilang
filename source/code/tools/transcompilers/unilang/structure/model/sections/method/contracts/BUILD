package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "contract_postcondition",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "contract_precondition",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "method_contracts_section",
    deps = [
        "contract_postcondition",
        "contract_precondition",
        "//code/utilities/types/vectors/operators:lib",
    ],
)
