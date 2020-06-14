package(default_visibility = ["//visibility:public"])

cc_library(
    name = "SFML_unhermetic",
    hdrs = glob(["include/SFML/**/*.h","include/SFML/**/*.hpp","include/SFML/**/*.inl", "include/SFML/src/**/*.inl",]),
    #defines = ["_REENTRANT"],
    includes = ["include"],
    #linkopts = [
    #    "-lsfml-graphics", "-lsfml-window", "-lsfml-system"
    #],
    visibility = ["//visibility:public"],
)
