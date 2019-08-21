
package(default_visibility = ["//visibility:public"])

cc_library(
    name = "sfml",
    hdrs = glob([
        "include/**/*.h",
        "include/**/*.hpp",
    ]
    ,exclude = [
    ]),
    includes = ["include","src","include/SFML","src/SFML"],
    
    srcs = glob([
        
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
        
    ]
    ,exclude = [
    ]),
    deps = [
        "@openal_soft//:openal_soft",
        "@stb//:stb",
        "@freetype2//:freetype2",
    ],
    copts = ["-UNone"]
)
