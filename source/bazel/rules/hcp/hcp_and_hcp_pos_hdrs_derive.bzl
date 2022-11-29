load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/hcp:hcp_pos.bzl", "hcp_pos")
load("//bazel/rules/hcp:hcp_pos_hdrs_derive.bzl", "hcp_pos_hdrs_derive")

#using the boot-strapped hcp compiler built from hcp files
def hcp_and_hcp_pos_hdrs_derive(
        name,
        interface_deps = [],  #deps & hdrs
        implementation_deps = [],  #deps & hdrs
        deps = [],
        data = []):
    hcp_hdrs_derive(name, 
                    interface_deps, 
                    implementation_deps, 
                    deps, 
                    data)
    
    hcp_pos_hdrs_derive(name, 
                        interface_deps, 
                        implementation_deps, 
                        deps, 
                        data)
