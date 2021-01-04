def data_getter(target_name, file_name, data_name):
    #rule
    native.genrule(
        name = target_name,
        srcs = [data_name],
        outs = [file_name],
        tools = ["//code/tools/transcompilers/data_getter:data_getter"],
        cmd = "$(location //code/tools/transcompilers/data_getter:data_getter) -i $(SRCS) -o $@",
    )
