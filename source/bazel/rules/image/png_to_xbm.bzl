def png_to_xbm(name):
    target_name = name + "_xbm"
    png_name = name + ".png"
    xbm_name = name + ".xbm"

    native.genrule(
        name = target_name,
        srcs = [png_name],
        outs = [xbm_name],
        cmd = """
              convert $(SRCS) $(OUTS)
              """,
    )
