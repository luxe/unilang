
def xpm_to_xbm(name):
    
    target_name = name + "_xbm"
    xpm_name = name + ".xpm"
    xbm_name = name + ".xbm"
    
    native.genrule(
        name = target_name,
        srcs = [xpm_name],
        outs = [xbm_name],
        cmd = """
              convert $(SRCS) $(OUTS)
              """
    )