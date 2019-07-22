
def mp3_artifact(name):
    
    native.filegroup(
        name = name + "_mp3_data",
        srcs = [name + ".mp3"],
    )