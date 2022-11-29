load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp/detail:hcp_hdrs_derive_specific.bzl", "hcp_hdrs_derive_specific")

#using the boot-strapped hcp compiler built from hcp files
def hcp_hdrs_derive(
        name,
        interface_deps = [],  #deps & hdrs
        implementation_deps = [],  #deps & hdrs
        deps = [],
        data = []):
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

    hcp_hdrs_derive_specific(
        name,
        explicit_hcp_file,  #file
        explicit_hpp_file,  #file
        explicit_cpp_file,  #file
        interface_deps,  #deps & hdrs
        implementation_deps,  #deps & hdrs
        real_deps,
        data,
    )
