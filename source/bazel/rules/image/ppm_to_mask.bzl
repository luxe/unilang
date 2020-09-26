def ppm_to_mask(name):
    target_name = name + "_ppm_mask"
    ppm_name = name + ".ppm"
    ppm_name_two = name + "_mask.ppm"

    native.genrule(
        name = target_name,
        srcs = [ppm_name],
        outs = [ppm_name_two],
        cmd = """
              ppmcolormask black $(SRCS) > $(OUTS);
              convert $(OUTS) -channel RGB -negate $(OUTS);
              """,
    )
