load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

def immediate_to_cpp(name,deps=[]):

    #the file names to use
    target_name = name + "_capnp"
    explicit_input_file = name + ".capnp_intermediate"
    explicit_result_h_file = name + ".hpp"
    
    #converting hcp to hpp/cpp
    native.genrule(
        name = target_name,
        srcs = [explicit_input_file],
        outs = [explicit_result_h_file],
        tools = ["@captnproto//:capnpc_cpp"],
        cmd = """
    $(location @captnproto//:capnpc_cpp) < $(SRCS) > $(OUTS)
        """
    )