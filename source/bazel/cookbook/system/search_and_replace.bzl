

def search_and_replace(name, file_from, file_to, find, replace):
    
    native.genrule(
        name = name,
        srcs = [file_from],
        outs = [file_to],
        output_to_bindir = 1,
        cmd = "sed 's/$find/$replace/g' $< > $@",
    )