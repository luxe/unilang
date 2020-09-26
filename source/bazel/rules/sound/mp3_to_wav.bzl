# or consider mpg123 -w output.wav input.mp3
def mp3_to_wav(name):
    target_name = name + "_wav"
    input = name + ".mp3"
    output = name + ".wav"

    native.genrule(
        name = target_name,
        srcs = [input],
        outs = [output],
        cmd = """
              ffmpeg -i $(SRCS) $(OUTS) 2>/dev/null
              """,
    )
