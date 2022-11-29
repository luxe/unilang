load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/hcp/detail:hcp_pos_hdrs_derive_specific.bzl", "hcp_pos_hdrs_derive_specific")

def hcp_pos_hdrs_derive(
        name,
        # interface_hdrs = [],  #hdr
        # implementation_hdrs = [],  #hdr
        interface_deps = [],  #deps & hdrs
        implementation_deps = [],  #deps & hdrs
        deps = [],
        data = []):
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

    hcp_pos_hdrs_derive_specific(
        name2,
        explicit_hcp_file,  #file
        explicit_hpp_file,  #file
        explicit_cpp_file,  #file
        # interface_hdrs,  #hdr
        # implementation_hdrs,  #hdr
        interface_deps,  #deps & hdrs
        implementation_deps,  #deps & hdrs
        real_deps,
        data,
    )
