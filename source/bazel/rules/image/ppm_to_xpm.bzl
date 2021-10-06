def ppm_to_xpm(name):
    target_name = name + "_xpm"
    ppm_name = name + ".ppm"
    xpm_name = name + ".xpm"

    native.genrule(
        name = target_name,
        srcs = [ppm_name],
        outs = [xpm_name],
        cmd = """
              ppmtoxpm $(SRCS) > $(OUTS) 2>/dev/null
              """,
    )
