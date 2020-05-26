package(default_visibility = ["//visibility:public"])

cc_library(
    name = "SDL2",
    hdrs = glob(["include/SDL2/*.h"]),
    defines = ["_REENTRANT"],
    includes = ["include/SDL2"],
    linkopts = [
        "-lSDL2",
        "-lSDL2_mixer",
    ],
    visibility = ["//visibility:public"],
)
