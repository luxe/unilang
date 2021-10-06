load("//bazel/rules/cpp:object.bzl", "cpp_object")

#using the boot-strapped hcp compiler built from hcp files
#this is an implementation-detail implementation called by more simple rules
#I don't intend this rule to be used directly by code writers
def hcp_hdrs_derive_specific(
        name,
        hcp_name,  #filename
        hpp_name,  #filename
        cpp_name,  #filename
        interface_hdrs,  #hdr
        implementation_hdrs,  #hdr
        interface_deps,  #deps & hdrs
        implementation_deps,  #deps & hdrs
        deps = [],  #deps
        data = []):  #deps
    #the file names to use
    hcp_target_name = name + "_hcp"

    interface_hdrs_cmd = ""
    if len(interface_hdrs) != 0:
        interface_hdrs_cmd = "--interface-hdrs {}".format(" --interface-hdrs ".join(interface_hdrs))

    implementation_hdrs_cmd = ""
    if len(implementation_hdrs) != 0:
        implementation_hdrs_cmd = "--implementation-hdrs {}".format(" --implementation-hdrs ".join(implementation_hdrs))

    interface_deps_cmd = ""
    if len(interface_deps) != 0:
        interface_deps_cmd = "--interface-deps {}".format(" --interface-deps ".join(interface_deps))

    implementation_deps_cmd = ""
    if len(implementation_deps) != 0:
        implementation_deps_cmd = "--implementation-deps {}".format(" --implementation-deps ".join(implementation_deps))

    #converting hcp to hpp/cpp
    native.genrule(
        name = hcp_target_name,
        srcs = [hcp_name],
        outs = [hpp_name, cpp_name],
        tools = ["//code/programs/transcompilers/hcp-compiler/official_hdrs_derive:hcp-compiler"],
        cmd = "$(location //code/programs/transcompilers/hcp-compiler/official_hdrs_derive:hcp-compiler) --input_files $(SRCS) -o $(@D) --output-base-name {} {} {} {} {}"
            .format(name, interface_hdrs_cmd, implementation_hdrs_cmd, interface_deps_cmd, implementation_deps_cmd),
    )

    #compiling hpp/cpp
    real_deps = list(deps)
    real_deps += interface_deps
    real_deps += implementation_deps
    cpp_object(name, real_deps, data)
