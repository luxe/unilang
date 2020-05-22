def xpm_to_ppm(name):
    target_name = name + "_ppm"
    xpm_name = name + ".xpm"
    ppm_name = name + ".ppm"

    native.genrule(
        name = target_name,
        srcs = [xpm_name],
        outs = [ppm_name],
        cmd = """
              xpmtoppm $(SRCS) > $(OUTS)
              """,
    )
