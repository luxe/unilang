def create_hello_world_file(name):
    native.genrule(
        name = name + "_target",
        outs = [name],
        output_to_bindir = 1,
        cmd = "echo 'hello world' > $@",
    )
