load("//bazel/rules/cpp:object.bzl", "cpp_object")

#using the boot-strapped hcp compiler built from hcp files
#this is an implementation-detail implementation called by more simple rules
#I don't intend this rule to be used directly by code writers
def hcp_pos_specific(name, hcp_name, hpp_name, cpp_name, deps = [], data = []):
    #the file names to use
    hcp_target_name = name + "_pos_hcp"

    #converting hcp to hpp/cpp
    native.genrule(
        name = hcp_target_name,
        srcs = [hcp_name],
        outs = [hpp_name, cpp_name],
        tools = ["//code/programs/transcompilers/hcp-compiler/official_pos:hcp-compiler"],
        cmd = "$(location //code/programs/transcompilers/hcp-compiler/official_pos:hcp-compiler) $(SRCS) -o $(@D) --output-base-name {}".format(name),
    )

    #compiling hpp/cpp
    cpp_object(name, deps, data)
