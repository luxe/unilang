load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

def capnp_to_intermediate(name, deps = []):
    #the file names to use
    target_name = name + "_capnp_intermediate"
    explicit_input_file = name + ".capnp"
    explicit_result_file = name + ".capnp_intermediate"

    #converting hcp to hpp/cpp
    native.genrule(
        name = target_name,
        srcs = [explicit_input_file],
        outs = [explicit_result_file],
        tools = ["@captnproto//:capnp_tool"],
        cmd = """
    $(location @captnproto//:capnp_tool) compile -o- $(SRCS) > $(OUTS)
        """,
    )
