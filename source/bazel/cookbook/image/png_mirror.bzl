def png_mirror(name):
    target_name = name + "_mirror"
    input = name + ".png"
    output = name + "_mirror.png"

    native.genrule(
        name = target_name,
        srcs = [input],
        outs = [output],
        cmd = """
              convert -flop $(SRCS) $(OUTS)
              """,
    )
