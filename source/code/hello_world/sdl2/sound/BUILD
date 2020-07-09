load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
    ],
    deps = [
        "@sdl2",
        #"@system//:SDL2",
        
        #"@SDL_mixer",
        "@system//:SDL2_mixer",
        "@system//:SDL2_hdrs",
        # "@tree",
        # "@boost//:serialization",
        # "@nlohmann_json//:nlohmann_json",
    ],
)
