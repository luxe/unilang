load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp/detail:hcp_pos_specific.bzl", "hcp_pos_specific")

#using the boot-strapped hcp compiler built from hcp files
def hcp_pos(name, deps = [], data = []):
    #the file names to use
    name2 = "positioned_" + name
    explicit_hcp_file = name + ".hcp"
    explicit_cpp_file = "positioned_" + name + ".cpp"
    explicit_hpp_file = "positioned_" + name + ".hpp"

    #compiling hpp/cpp
    real_deps = list(deps)
    real_deps += ["@boost//:serialization"]
    real_deps += ["@nlohmann_json//:nlohmann_json"]
    real_deps += ["//code/utilities/data_structures/position:position"]
    real_deps += ["//code/utilities/formats/json/overloads:tree_json_converters"]
    real_deps += ["//code/utilities/formats/json/overloads:chrono_json_converters"]

    hcp_pos_specific(name2, explicit_hcp_file, explicit_hpp_file, explicit_cpp_file, real_deps, data)
