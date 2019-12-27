def create_file_with_epoch(name):
    
    target_name = name
    outfile = name + "_epoch"
    
    native.genrule(
        name = target_name,
        srcs = [],
        outs = [outfile],
        cmd = """
              date +'%s' > $(OUTS)
              """
    )