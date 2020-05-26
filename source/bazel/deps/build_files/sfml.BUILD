package(default_visibility = ["//visibility:public"])

cc_library(
    name = "sfml",
    srcs = glob(
        [
            "src/SFML/Audio/**/*.hpp",
            "src/SFML/Audio/**/*.cpp",
            "src/SFML/Graphics/**/*.hpp",
            "src/SFML/Graphics/**/*.cpp",

            #"src/SFML/Main/SFMLActivity.cpp",
            "src/SFML/Network/Unix/**/*.hpp",
            "src/SFML/Network/Unix/**/*.cpp",
            "src/SFML/Network/*.hpp",
            "src/SFML/Network/*.cpp",
            "src/SFML/System/Unix/**/*.hpp",
            "src/SFML/System/Unix/**/*.cpp",
            "src/SFML/System/*.hpp",
            "src/SFML/System/*.cpp",
            "src/SFML/Window/Unix/**/*.hpp",
            "src/SFML/Window/Unix/**/*.cpp",
            "src/SFML/Window/*.hpp",
            "src/SFML/Window/*.cpp",
            "src/SFML/**/*.inl",
        ],
        exclude = [
        ],
    ),
    hdrs = glob(
        [
            "include/**/*.h",
            "include/**/*.hpp",
            "src/**/*.inl",
            "include/**/*.inl",
        ],
        exclude = [
        ],
    ),
    copts = ["-UNone"],
    includes = [
        "include",
        "include/SFML",
        "include/SFML/Main",
        "include/SFML/Network",
        "include/SFML/System",
        "include/SFML/Window",
        "include/SFML/Window/Unix",
        "src",
        "src/SFML",
    ],
    linkopts = [
        "-lopenal",
        "-lFLAC",
        "-lvorbis",
        "-lvorbisenc",
        "-logg",
        "-lvorbisfile",
    ],
    deps = [
        "@freetype2",
        "@openal_soft",
        "@stb",
        "@x11",
    ],
)
