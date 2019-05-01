load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

def intermediate_to_cpp(name,deps=[]):

    #the file names to use
    target_name = name + "_capnp"
    explicit_input_file = name + ".capnp_intermediate"
    explicit_result_h_file = name + ".capnp.h"
    explicit_result_cpp_file = name + ".capnp.c++"
    
    #converting hcp to hpp/cpp
    native.genrule(
        name = target_name,
        srcs = [explicit_input_file],
        outs = [explicit_result_h_file,explicit_result_cpp_file],
        tools = ["@captnproto//:capnpc_cpp"],
        output_to_bindir = False,
        cmd = """
    $(location @captnproto//:capnpc_cpp) < $(SRCS);
    cp -r code $(GENDIR)
        """
    )