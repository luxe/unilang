load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp/detail:hcp_specific.bzl", "hcp_specific")

#using the boot-strapped hcp compiler built from hcp files
def hcp(name, deps = [], data = []):
    #the file names to use
    explicit_hcp_file = name + ".hcp"
    explicit_hpp_file = name + ".hpp"
    explicit_cpp_file = name + ".cpp"

    #compiling hpp/cpp
    real_deps = list(deps)
    real_deps += ["@boost//:serialization"]
    real_deps += ["@nlohmann_json//:nlohmann_json"]
    real_deps += ["//code/utilities/formats/json/overloads:tree_json_converters"]
    real_deps += ["//code/utilities/formats/json/overloads:chrono_json_converters"]

    hcp_specific(name, explicit_hcp_file, explicit_hpp_file, explicit_cpp_file, real_deps, data)
