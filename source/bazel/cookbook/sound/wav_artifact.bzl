
def wav_artifact(name):
    
    native.filegroup(
        name = name + "_wav_data",
        srcs = [name + ".wav"],
    )