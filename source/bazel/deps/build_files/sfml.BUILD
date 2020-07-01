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
    copts = [
        #"-UNone",
        #"-DSFML_OPENGL_ES",
        "-DSFML_SYSTEM_LINUX",
        "-pthread",
    ],
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
        "-ludev",
        #"-lpthread",
        #"-GL",
    ],
    deps = [
        #"@mesa",
        #"@mesa//:mesa_hdrs",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
        "@system//:EGL_hdrs",
        "@flac",
        "@freetype2",
        "@openal_soft",
        "@stb",
        #"@systemd//:libudev",
        "@debian_stretch_amd64_sysroot//:udev",
        "@debian_stretch_amd64_sysroot//:udev_hdrs",
        "@vorbis",
        "@x11",
        "@xorg_libXrandr",
        "@system//:SDL_mixer",
        "@system//:openal",
    ],
)

cc_library(
    name = "sfml_unhermetic",
    deps = [
        "@system//:SFML_hdrs",
        "@system//:SFML_audio",
        "@system//:SFML_graphics",
        "@system//:SFML_network",
        "@system//:SFML_system",
        "@system//:SFML_window",
        "@system//:SDL2_mixer",
    ]
)