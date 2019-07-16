
def png_to_xpm(name):
    
    target_name = name + "_xpm"
    png_name = name + ".png"
    xpm_name = name + ".xpm"
    
    native.genrule(
        name = target_name,
        srcs = [png_name],
        outs = [xpm_name],
        cmd = """
              convert $(SRCS) $(OUTS)
              """
    )