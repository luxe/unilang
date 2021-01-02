

def unilang_to_code(name):
    
    #implicit file names
    input_name = name + ".unilang"
    output_name = name + ".json"
    target_name = name + "_json"
    output_target_name = name + "_json_data"
    
    #rule
    native.genrule(
        name = target_name,
        srcs = [input_name],
        outs = [output_name],
        tools = ["//code/tools/transcompilers/unilang/unilang_to_code:unilang_to_code"],
        cmd = "$(location //code/tools/transcompilers/unilang/unilang_to_code:unilang_to_code) -i $(SRCS) -o $@",
    )
    
    native.filegroup(
        name = output_target_name,
        srcs = [target_name],
    )
